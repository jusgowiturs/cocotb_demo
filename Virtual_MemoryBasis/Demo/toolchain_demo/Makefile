# Each command followed by @ symbol will execute, otherwise by default
# make prints each command it executes (called "echoing") before running it

obj-m += hello.o
test:
	@echo "Hello, Make!"
 
all:
	@echo "Compiling ..."
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	@echo "Cleaning ..."
	@make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
