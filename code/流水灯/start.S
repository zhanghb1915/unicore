.section .init
.global _start
.type _start,@function
_start:
nop
nop
nop
#csrrci x0, mstatus, 0x8
.option push
.option norelax
.option pop
li sp, 0x80000800

call main
#tail exit
#call __libc_init_array
1:
j 1b
