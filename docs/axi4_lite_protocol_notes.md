# AXI4-Lite Protocol Notes

## Global Signals

- `ACLK`: clock
- `ARESETN`: active-low reset

All AXI4-Lite signals are sampled on the rising edge of `ACLK`.

## Handshake Rule

Each channel transfers information using a `VALID` / `READY` handshake.

- The source asserts `VALID` when address, data, or response information is available.
- The destination asserts `READY` when it can accept that information.
- The handshake completes on a rising clock edge when both `VALID` and `READY` are high.

## Read Channels

### Read Address Channel

- `ARADDR`: read address
- `ARPROT`: protection attributes
- `ARVALID`: master indicates read address is valid
- `ARREADY`: slave indicates it can accept the read address

### Read Data Channel

- `RDATA`: read data
- `RRESP`: read response
- `RVALID`: slave indicates read data is valid
- `RREADY`: master indicates it can accept read data

## Write Channels

### Write Address Channel

- `AWADDR`: write address
- `AWPROT`: protection attributes
- `AWVALID`: master indicates write address is valid
- `AWREADY`: slave indicates it can accept the write address

### Write Data Channel

- `WDATA`: write data
- `WSTRB`: byte write strobes
- `WVALID`: master indicates write data is valid
- `WREADY`: slave indicates it can accept write data

### Write Response Channel

- `BRESP`: write response
- `BVALID`: slave indicates write response is valid
- `BREADY`: master indicates it can accept the write response

## Read Transaction Order

1. Master drives `ARADDR` and asserts `ARVALID`.
2. Slave asserts `ARREADY` when it can accept the address.
3. The read address handshake completes when `ARVALID` and `ARREADY` are high on a rising clock edge.
4. Slave drives `RDATA`, drives `RRESP`, and asserts `RVALID`.
5. Master asserts `RREADY` when it can accept the data.
6. The read data handshake completes when `RVALID` and `RREADY` are high on a rising clock edge.

## Write Transaction Order

1. Master drives `AWADDR` and asserts `AWVALID`.
2. Master drives `WDATA`, `WSTRB`, and asserts `WVALID`.
3. Slave accepts write address when `AWVALID` and `AWREADY` handshake.
4. Slave accepts write data when `WVALID` and `WREADY` handshake.
5. After both write address and write data handshakes complete, slave drives `BRESP` and asserts `BVALID`.
6. Master asserts `BREADY` when it can accept the response.
7. The write response handshake completes when `BVALID` and `BREADY` are high on a rising clock edge.

The write address and write data handshakes are independent. They may happen in either order or at the same time.

## Common Response Values

- `2'b00`: OKAY
- `2'b10`: SLVERR
- `2'b11`: DECERR

