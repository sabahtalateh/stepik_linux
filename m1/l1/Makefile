DIR := ${CURDIR}

build:			lib link export_ld

lib:        	hello.c hello.h
				gcc -o libHello.so -shared -fPIC hello.c

link:      		lib main.c
				gcc main.c -L. -lHello -o hello

export_ld:
				export LD_LIBRARY_PATH=$(DIR)

clean:
				-rm hello libHello.so *.o 2>/dev/null


