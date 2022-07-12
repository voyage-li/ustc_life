onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib dist_mem_gen_4_opt

do {wave.do}

view wave
view structure
view signals

do {dist_mem_gen_4.udo}

run -all

quit -force
