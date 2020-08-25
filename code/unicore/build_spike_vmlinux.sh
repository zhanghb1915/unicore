#!/bin/bash
cd busybox-1.30.1/
cd root/
find . | cpio --quiet -o -H newc | gzip > ../../linux-4.20/rootfs.cpio.gz
cd ../../linux-4.20
make clean
make -j4 ARCH=riscv CROSS_COMPILE=riscv64-unknown-linux-gnu- vmlinux
cd ../../fpga-rocket-chip/
make clean
make sd_image VMLINUX=/home/zhb/rocket-tools/riscv-linux/linux-4.20/vmlinux
cd firmware/
riscv64-unknown-linux-gnu-gcc -nostdlib -static -fno-builtin-printf -T linker.ld -I ./driver head.S sdload.c ./driver/uart.c ./driver/myprintf.c ./driver/elf.c ./driver/spi.c ./driver/diskio.c ./driver/ff.c ./driver/memory.c  -o firmware.elf -mcmodel=medany


