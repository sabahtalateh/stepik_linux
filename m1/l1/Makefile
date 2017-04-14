build: 		link objects

link:		objects
			gcc -o hello hello.o main.o

objects:	hello.h hello.c main.c
			gcc -o hello.o -c hello.c; gcc -o main.o -c main.c

clean:
			-rm hello libHello.so *.o 2>/dev/null


