obj-m	:= my_module_1.o ________

KDIR	:= /lib/modules/$(shell uname -r)/build
#KDIR	:= /work_kernel/linux
#PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$$PWD modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$$PWD clean
