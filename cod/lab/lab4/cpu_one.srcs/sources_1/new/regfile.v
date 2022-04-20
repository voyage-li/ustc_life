module register_file(
    input clk,
    input [4:0] ra0,
    output [31:0] rd0,
    input [4:0] ra1,
    output [31:0] rd1,
    input [4:0] wa,
    input we,
    input [31:0] wd,
    input [4:0] ra2,
    output [31:0] reg_debug 
);

    reg [31:0] regfile[0:31];
    initial begin
        regfile[0]=0;
        regfile[1]=0;
        regfile[2]=0;
        regfile[3]=0;
        regfile[4]=0;
        regfile[5]=0;
        regfile[6]=0;
        regfile[7]=0;
        regfile[8]=0;
        regfile[9]=0;
        regfile[10]=0;
        regfile[11]=0;
        regfile[12]=0;
        regfile[13]=0;
        regfile[14]=0;
        regfile[15]=0;
        regfile[16]=0;
        regfile[17]=0;
        regfile[18]=0;
        regfile[19]=0;
        regfile[20]=0;
        regfile[21]=0;
        regfile[22]=0;
        regfile[23]=0;
        regfile[24]=0;
        regfile[25]=0;
        regfile[26]=0;
        regfile[27]=0;
        regfile[28]=0;
        regfile[29]=0;
        regfile[30]=0;
        regfile[31]=0;
    end
    assign rd0 = regfile[ra0];
    assign rd1 = regfile[ra1];
    
    always @(posedge clk) begin
        if (we == 1)
            regfile[wa] <= wd;
    end

endmodule