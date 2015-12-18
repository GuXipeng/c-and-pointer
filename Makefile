obj = ex1-1.o
BUILD_OUTPUT := build/
all:$(obj)
	-$(shell mkdir build)
	gcc $(obj) -o $(BUILD_OUTPUT)ex1-1
.PHONY:all

ex1-1.o:
	gcc  -c ex1-1.c

ex1-2:
	gcc ex1-2.c -o build/ex1-2
clean:
	rm -rf *.o ./build *~
