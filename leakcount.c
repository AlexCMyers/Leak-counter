/* Alexandra Myers
 * leakcount.c
After running "make" leakcount takes in another program (and if present, that 
program's arguments) as its arguments (Ex: ./leakcount ./a.out in.txt
It uses fork() and execvpe() to have a child process run the other program. 
Using a shim called memory_shim.so and its constructor and destructor, the other
programs calls to malloc() and free() are recorded.  At calls to malloc,
pointers to the memory blocks created by the usual malloc function are stored
in a linked list of void pointers. Calls to free result in the removal of these
pointers from the linked list. If any memory is left unfreed, then the 
shim's destructor outputs a description of that memory to stderr
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int i = 0;
	char* arguments[argc];
	//uses a shim I made to pass as environment variable later on
	char *const environment[] = {"LD_PRELOAD=./memory_shim.so", NULL};

	//looping to pick up all arguments
	for(i = 1; i < argc; i++){
		arguments[i - 1] = argv[i];
	}
	//setting NULL per execve parameter rules
	arguments[argc - 1] = NULL;
	
	//fork, child goes into if block
	if(fork() == 0){
		//starts program argv[1] with arguments as its arguments
		execve(argv[1], arguments, environment);
	}
	//waiting for all child processes to finish
	wait(NULL);

	return 0;
}


