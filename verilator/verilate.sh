verilator \
-cc -exe --public --trace --savable \
--compiler msvc +define+SIMULATION=1 \
-O3 --x-assign fast --x-initial fast --noassert \
--converge-limit 6000 \
-Wno-fatal \
--top-module top sim.v \
../rtl/oricatmos.sv \
../rtl/ram.sv \
../rtl/cassette.v \
../rtl/square_gen.v \
../rtl/bram.v \
../rtl/wd1793.sv \
../rtl/keyboard.sv \
../rtl/microdisc.sv \
../rtl/rom/MICRODIS.sv \
../rtl/rom/BASIC10.sv \
../rtl/rom/BASIC11A.sv \
../rtl/ula.sv \
../rtl/tv65/t65.v \
../rtl/tv65/t65_mcode.v \
../rtl/tv65/t65_pack.sv \
../rtl/tv65/t65_alu.v \
../rtl/video.sv \
../rtl/m6522.sv \
../rtl/dpram.v \
../rtl/jt49/hdl/jt49_bus.v \
../rtl/jt49/hdl/jt49_cen.v \
../rtl/jt49/hdl/jt49_div.v \
../rtl/jt49/hdl/jt49_eg.v \
../rtl/jt49/hdl/jt49_exp.v \
../rtl/jt49/hdl/jt49_noise.v \
../rtl/jt49/hdl/jt49.v