#obj-m += pqled.o
#obj-m += pqrowled.o
#obj-m += pqbutton.o
obj-m += dvrowled.o
#obj-m += pandma.o
#obj-m += pqmap.o
#obj-m += pqpspl.o
# pqdmad-objs := pqrdma_driver.o circ_queue.o

all:
	make -C /home/vishwajith/work/linux_device_drivers/Linux-Digilent-Dev/ M=/home/vishwajith/work/linux_device_drivers/codes modules
	# arm-xilinx-linux-gnueabi-gcc-4.9.1 -c -Wall -Werror -fPIC pqrdma.c
	# arm-xilinx-linux-gnueabi-gcc-4.9.1 -shared -o libpqrdma.so pqrdma.o
	#make -o pqrdma -lm pqrdma.c
	#make  -o pqrdma.o pqrdma.c
clean:
	make -C /home/vishwajith/work/linux_device_drivers/Linux-Digilent-Dev/ M=/home/vishwajith/work/linux_device_drivers/codes clean
