CROSS_COMPLE:=riscv64-unknown-linux-gnu-
ARCH:=riscv
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)ld


obj-m := idct.o
module-objs = idct.o


#KDIR := /root/eastcom/susz_view_server_test/SW_COMM/lib/SW_BPS/Terminal/D8135/CPU/LinuxSys/Kernel
KDIR := /home/lidz/riscv/linux-4.20
PWD := $(shell pwd)
defaule:
	make -C $(KDIR) M=$(PWD) modules ARCH=riscv CROSS_COMPILE=riscv64-unknown-linux-gnu-


clean:
	rm -f *.ko *.o *.mod.c *.symvers

