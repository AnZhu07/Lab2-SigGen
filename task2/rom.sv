module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 8
)(
    input logic                      clk,
    input logic [ADDRESS_WIDTH-1:0] addr,
    input logic [DATA_WIDTH-1:0]    off,
    output logic [DATA_WIDTH-1:0]   dout,
    output logic [DATA_WIDTH-1:0]   dout2
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $display("Loading rom.");
    $readmemh("sinerom.mem", rom_array);
end;

always_ff @(posedge clk)
    begin
    // output is synchronous
    dout <= rom_array [addr];
    dout2 <= rom_array [addr+off];
    end

endmodule
