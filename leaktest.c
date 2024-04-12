#include <stdio.h>
//tester for leak


#include <stdlib.h>

int main(int argc, char **argv)
{
	void *p1, *p2, *p3, *p4;
	
	//freed
	p1 = malloc(1345); 	
	//freed
	p2 = malloc(2); 
	free(p1);
	//leak
	p1 = malloc(134);	
	free(p2);
	
	//freed
	p3 = malloc(1);
	//freed
	p4 = malloc(981);	
	free (p4);
	free(p3);

	printf("Hello World\n");
}
