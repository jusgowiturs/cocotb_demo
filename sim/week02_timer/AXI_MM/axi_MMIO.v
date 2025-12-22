module simple_axil_slave #(
    parameter ADDR_WIDTH = 6,
    parameter DATA_WIDTH = 32
)(
    input  wire                   ACLK,
    input  wire                   ARESETn,

    // AXI4-Lite Write Address Channel
    input  wire [ADDR_WIDTH-1:0]  saxi_awaddr,
    input  wire                  saxi_awvalid,
    output wire                  saxi_awready,

    // AXI4-Lite Write Data Channel
    input  wire [DATA_WIDTH-1:0]  saxi_wdata,
    input  wire [DATA_WIDTH/8-1:0] saxi_wstrb,
    input  wire                  saxi_wvalid,
    output wire                  saxi_wready,

    // AXI4-Lite Write Response Channel
    output reg  [1:0]             saxi_bresp,
    output reg                   saxi_bvalid,
    input  wire                  saxi_bready,

    // AXI4-Lite Read Address Channel
    input  wire [ADDR_WIDTH-1:0]  saxi_araddr,
    input  wire                  saxi_arvalid,
    output wire                  saxi_arready,

    // AXI4-Lite Read Data Channel
    output reg  [DATA_WIDTH-1:0]  saxi_rdata,
    output reg  [1:0]             saxi_rresp,
    output reg                   saxi_rvalid,
    input  wire                  saxi_rready
);

  localparam OKAY = 2'b00;

  // Register space: 4 registers (0x00, 0x04, 0x08, 0x0C)
  reg [DATA_WIDTH-1:0] registers [0:3];

  // AXI-Lite handshake signals
  reg aw_hs, w_hs, ar_hs;
  reg [ADDR_WIDTH-1:0] awaddr_reg, araddr_reg;

  // Write address handshake
  assign saxi_awready = ~aw_hs;
  always @(posedge ACLK or negedge ARESETn) begin
    if (!ARESETn)
      aw_hs <= 0;
    else if (~aw_hs && saxi_awvalid && saxi_awready) begin
      aw_hs <= 1;
      awaddr_reg <= saxi_awaddr;
    end else if (saxi_bvalid && saxi_bready)
      aw_hs <= 0;
  end

  // Write data handshake
  assign saxi_wready = ~w_hs;
  always @(posedge ACLK or negedge ARESETn) begin
    if (!ARESETn)
      w_hs <= 0;
    else if (~w_hs && saxi_wvalid && saxi_wready) begin
      w_hs <= 1;
    end else if (saxi_bvalid && saxi_bready)
      w_hs <= 0;
  end

  // Write logic
  wire do_write = aw_hs && w_hs && ~saxi_bvalid;
  integer i;
  always @(posedge ACLK) begin
    if (do_write) begin
      // Address decode for 4 registers, word aligned (ignore top bits)
      case (awaddr_reg[3:2])
        2'd0: for (i = 0; i < DATA_WIDTH/8; i = i + 1)
                if (saxi_wstrb[i]) registers[0][i*8 +: 8] <= saxi_wdata[i*8 +: 8];
        2'd1: for (i = 0; i < DATA_WIDTH/8; i = i + 1)
                if (saxi_wstrb[i]) registers[1][i*8 +: 8] <= saxi_wdata[i*8 +: 8];
        2'd2: for (i = 0; i < DATA_WIDTH/8; i = i + 1)
                if (saxi_wstrb[i]) registers[2][i*8 +: 8] <= saxi_wdata[i*8 +: 8];
        2'd3: for (i = 0; i < DATA_WIDTH/8; i = i + 1)
                if (saxi_wstrb[i]) registers[3][i*8 +: 8] <= saxi_wdata[i*8 +: 8];
      endcase
    end
  end

  // Write response logic
  always @(posedge ACLK or negedge ARESETn) begin
    if (!ARESETn) begin
      saxi_bvalid <= 0;
      saxi_bresp <= OKAY;
    end else if (do_write) begin
      saxi_bvalid <= 1;
      saxi_bresp <= OKAY;
    end else if (saxi_bvalid && saxi_bready) begin
      saxi_bvalid <= 0;
    end
  end

  // Read address handshake
  assign saxi_arready = ~ar_hs && ~saxi_rvalid;
  always @(posedge ACLK or negedge ARESETn) begin
    if (!ARESETn)
      ar_hs <= 0;
    else if (~ar_hs && saxi_arvalid && saxi_arready) begin
      ar_hs <= 1;
      araddr_reg <= saxi_araddr;
    end else if (saxi_rvalid && saxi_rready)
      ar_hs <= 0;
  end

  // Read logic
  always @(posedge ACLK) begin
    if (ar_hs) begin
      case (araddr_reg[3:2])
        2'd0: saxi_rdata <= registers[0];
        2'd1: saxi_rdata <= registers[1];
        2'd2: saxi_rdata <= registers[2];
        2'd3: saxi_rdata <= registers[3];
        default: saxi_rdata <= 0;
      endcase
      saxi_rresp <= OKAY;
      saxi_rvalid <= 1;
    end else if (saxi_rvalid && saxi_rready) begin
      saxi_rvalid <= 0;
    end
  end

endmodule
