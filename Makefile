obj = ex1-1.o
all:$(obj)
	gcc $(obj) -o ./build/ex1-1
.PHONY:all

ex1-1.o:
	gcc  -c ex1-1.c

ex1-2:
	gcc ex1-2.c -o build/ex1-2
clean:
	rm -rf *.o ./build/* *~
