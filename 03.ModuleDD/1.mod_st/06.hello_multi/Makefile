obj-m += hello_multi.o
__________ := hello_start.o hello_stop.o

KDIR	:= /lib/modules/$(shell uname -r)/build
#PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) M=$$PWD modules
clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$$PWD clean
	