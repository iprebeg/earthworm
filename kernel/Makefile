obj-m += earthworm.o
#obj-m += unlinkat.o

all:
	./find_syscalltable.sh
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rm -f syscall_table.h
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
