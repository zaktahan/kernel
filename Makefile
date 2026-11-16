ARCH := arm64
CROSS_COMPILE := $(HOME)/rpi-buildroot-2026.08/output/host/bin/aarch64-linux-

obj-m := hello.o

ROOTDIR := $(HOME)/rpi-buildroot-2026.08/output/build/linux-custom
PWD := $(shell pwd)

default:
	$(MAKE) -C $(ROOTDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules

clean:
	$(MAKE) -C $(ROOTDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) clean
