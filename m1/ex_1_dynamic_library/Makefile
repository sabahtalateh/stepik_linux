app:	exe lib

exe:	solution.c main.c lib
		gcc main.c -fPIC -L. -lsolution -o main

lib:	solution.c
		gcc -shared solution.c -fPIC -o libsolution.so

clean:
		-rm main libsolution.so *.o 2>/dev/null
