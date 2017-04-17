build:			lib link

link:      		lib main.c
				gcc main.c -fPIC -ldl -o hello

lib:        	hello.c hello.h
				gcc -o libHello.so -shared -fPIC hello.c

clean:
				-rm hello libHello.so *.o 2>/dev/null


