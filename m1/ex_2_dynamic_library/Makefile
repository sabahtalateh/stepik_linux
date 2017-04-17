exe:			solution.c
				gcc solution.c -ldl -fPIC -o solution -Wl,-rpath,.

lib: 			lib.c lib.h
				gcc -o libLib.so -shared -fPIC lib.c

clean:
				-rm *.so solution 2>/dev/null
