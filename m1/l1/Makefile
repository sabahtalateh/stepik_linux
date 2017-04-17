build: 		link objects

link:		objects
			gcc -o hello hello.o main.o

objects:	hello.h hello.c main.c
		    gcc -o hello.o -c hello.c; gcc -o main.o -c main.c







build2:     lib link2 export_ld

lib:        hello.c hello.h
			gcc -o libHello.so -shared -fPIC hello.c

export_ld:
			export LD_LIBRARY_PATH=.

link2:      lib main.c
			gcc main.c -L. -lHello -o hello






clean:
			-rm hello libHello.so *.o 2>/dev/null


