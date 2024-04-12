CC = gcc

programs: leakcount.c memory_shim.c leaktest.c 
	gcc -Wall -o leakcount leakcount.c
	$(CC) -c -Wall -fpic memory_shim.c
	$(CC) -shared -o memory_shim.so memory_shim.o -ldl
	rm memory_shim.o
	$(CC) -Wall leaktest.c -o test

run: 
	./leakcount test

clean:  
	rm leakcount
	rm test
	rm memory_shim.so
