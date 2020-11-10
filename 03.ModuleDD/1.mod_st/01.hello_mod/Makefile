obj-m	:= hello_mod.o

KDIR	:= /lib/modules/$(shell uname -r)/build
#KDIR	:= /work_kernel/linux
#PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$$PWD modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$$PWD clean

