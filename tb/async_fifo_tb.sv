`timescale 1ns/1ps
`default_nettype none

module async_fifo_tb;

    localparam int DATA_W = 8;
    localparam int ADDR_W = 2;
    localparam int NUM_WORDS = 200;

    logic [DATA_W-1:0] exp_q [$]; // queue <- reference model
    int errors = 0;
    int writes = 0;
    int reads = 0;
    int full_cycles = 0;
    int empty_cycles = 0;

    logic [DATA_W-1:0] expected;
    int wclk_period = 10;
    int rclk_period = 17;

    logic wclk;
    logic wrst_n;
    logic wr_en;
    logic [DATA_W-1:0] wdata;
    logic full;

    logic rclk;
    logic rrst_n;
    logic rd_en;
    logic [DATA_W-1:0] rdata;
    logic empty;

    // Read plusargs, set start values and toggle forever
    initial begin
        void'($value$plusargs("WCLK=%d", wclk_period));
        void'($value$plusargs("RCLK=%d", rclk_period));
        wclk = 0;
        rclk = 0;
        fork
            forever #(wclk_period/2.0) wclk = ~wclk;
            forever #(rclk_period/2.0) rclk = ~rclk;
        join_none
    end

    // Write side reset: hold low for 3 wclk edges
    initial begin
        wrst_n = 0;
        wr_en  = 0;
        wdata  = '0;
        repeat (3) @(posedge wclk);
        wrst_n = 1;
    end

    // Read side reset: hold low for 3 rclk edges
    initial begin
        rrst_n = 0;
        rd_en  = 0;
        repeat (3) @(posedge rclk);
        rrst_n = 1;
    end

    async_fifo #(
        .DATA_W(DATA_W),
        .ADDR_W(ADDR_W)
    ) dut (
        .wclk(wclk),
        .wrst_n(wrst_n),
        .wr_en(wr_en),
        .wdata(wdata),
        .full(full),
        .rclk(rclk),
        .rrst_n(rrst_n),
        .rd_en(rd_en),
        .rdata(rdata),
        .empty(empty)
    );

    // Scoreboard: the FIFO's job is that what goes in comes out in the same order, nothing lost or added

    // Write-side monitor: records every write the FIFO accepts
    // wr_en && !full is the same condition under which the FIFO stores a word
    // (same expression as fifo_mem and fifo_wptr_full), so the queue records exactly what the FIFO stored
    always @(posedge wclk) begin
        if (wrst_n && wr_en && !full) begin
            exp_q.push_back(wdata);
            writes++;
        end
    end

    // Read-side monitor: every word the FIFO gives out must match the oldest expected value
    // rd_en && !empty is when the FIFO's read pointer moves, so a word is actually leaving the FIFO
    // rdata at the clock edge is the word being taken
    // exp_q.size() == 0 means the FIFO handed out data that was never written (the ~empty check failed)
    // !== instead of != also counts X as a mismatch; with != comparing X gives X, which the if treats as false
    always @(posedge rclk) begin
        if (rrst_n && rd_en && !empty) begin
            if (exp_q.size() == 0) begin
                $error("FIFO output 0x%02h but nothing was written", rdata);
                errors++;
            end else begin
                expected = exp_q.pop_front();
                if (rdata !== expected) begin
                    $error("Data mismatch: expected 0x%02h, got 0x%02h", expected, rdata);
                    errors++;
                end
                reads++;
            end
        end
    end

    // Main test sequence
    initial begin : main
        int writes_at_full;
        int target;

        // Wait until both domains are out of reset
        wait (wrst_n && rrst_n);

        // Phase 1: fill. Write with no reads until the FIFO reports full
        $display("[%0t] Phase 1: fill", $time);
        do begin
            @(negedge wclk);
            wr_en = 1'b1;
            wdata = DATA_W'(writes);
        end while (!full);

        // Keep trying to write for 10 more cycles; none of them should be accepted
        writes_at_full = writes;
        repeat (10) begin
            @(negedge wclk);
            wdata = DATA_W'(writes);
        end
        wr_en = 1'b0;

        if (writes != writes_at_full) begin
            $error("Writes accepted while full: %0d extra", writes - writes_at_full);
            errors++;
        end

        if (exp_q.size() != 2**ADDR_W) begin
            $error("Full asserted at %0d entries, expected %0d", exp_q.size(), 2**ADDR_W);
            errors++;
        end

        // Phase 2: drain. Read with no writes until the FIFO reports empty
        $display("[%0t] Phase 2: drain", $time);
        do begin
            @(negedge rclk);
            rd_en = 1'b1;
        end while (!empty);

        // Keep trying to read for 10 more cycles; none of them should be accepted
        repeat (10) @(negedge rclk);
        rd_en = 1'b0;

        if (reads != writes) begin
            $error("Drain mismatch: wrote %0d, read %0d", writes, reads);
            errors++;
        end

        if (exp_q.size() != 0) begin
            $error("%0d words still expected after drain", exp_q.size());
            errors++;
        end

        // Phase 3: random traffic on both sides at the same time
        $display("[%0t] Phase 3: random", $time);
        target = writes + NUM_WORDS;
        full_cycles  = 0;  // count coverage for the random phase only
        empty_cycles = 0;
        fork
            // Writer: random wr_en until NUM_WORDS more writes are accepted
            begin
                @(negedge wclk);
                while (writes < target) begin
                    wr_en = 1'($urandom_range(0, 1));
                    wdata = DATA_W'(writes);
                    @(negedge wclk);
                end
                wr_en = 1'b0;
            end

            // Reader: random rd_en until every word has been read
            begin
                @(negedge rclk);
                while (reads < target) begin
                    rd_en = 1'($urandom_range(0, 1));
                    @(negedge rclk);
                end
                rd_en = 1'b0;
            end
        join

        // Final result
        if (exp_q.size() != 0) begin
            $error("%0d words still expected at end of test", exp_q.size());
            errors++;
        end

        $display("Coverage: full high %0d wclk cycles, empty high %0d rclk cycles",
            full_cycles, empty_cycles);
        if (full_cycles == 0 || empty_cycles == 0) begin
            $warning("Random phase never reached full or empty; try another clock ratio");
        end

        if (errors == 0) begin
            $display("PASS: writes=%0d reads=%0d (wclk=%0dns rclk=%0dns)",
                writes, reads, wclk_period, rclk_period);
        end else begin
            $display("FAIL: %0d errors, writes=%0d reads=%0d (wclk=%0dns rclk=%0dns)",
                errors, writes, reads, wclk_period, rclk_period);
        end
        $finish;
    end

    // Coverage counters: how often the FIFO actually reached full and empty
    always @(posedge wclk) begin
        if (wrst_n && full) full_cycles++;
    end

    always @(posedge rclk) begin
        if (rrst_n && empty) empty_cycles++;
    end

    // Assertions: each Gray pointer may change at most one bit per clock in its own domain.
    // These check the source pointers only. The synchronized copies (wq2_rptr, rq2_wptr)
    // can legitimately jump several counts when a fast clock is sampled by a slow one.
    assert property (@(posedge wclk) disable iff (!wrst_n) $onehot0(dut.wptr ^ $past(dut.wptr)))
        else begin
            $error("Write Gray pointer changed more than one bit (now %b)", dut.wptr);
            errors++;
        end

    assert property (@(posedge rclk) disable iff (!rrst_n) $onehot0(dut.rptr ^ $past(dut.rptr)))
        else begin
            $error("Read Gray pointer changed more than one bit (now %b)", dut.rptr);
            errors++;
        end

    // Timeout: a hang (e.g. full or empty never asserting) fails clearly instead of running forever
    initial begin
        #1_000_000;
        $fatal(1, "Timeout: writes=%0d reads=%0d full=%b empty=%b", writes, reads, full, empty);
    end

endmodule

`default_nettype wire
