build: 	exe lib

exe:	hello.h main.c lib lib
		gcc main.c -fPIC -L. -lHello -o hello

lib:	hello.h hello.c
		gcc -shared hello.c -fPIC -o libHello.so

clean:
		-rm hello libHello.so *.o 2>/dev/null
