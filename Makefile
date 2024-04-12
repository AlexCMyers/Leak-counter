CC = gcc

programs: leakcount.c memory_shim.c leaktest.c 
	$(CC) -Wall -o leakcount leakcount.c
	$(CC) -Wall leaktest.c -o test

run: 
	./leakcount test

clean:  
	rm leakcount
	rm test
