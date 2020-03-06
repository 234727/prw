#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

void main(int argc, char *argv[])
{
	int i, steps;
    // char buf[10];
	i = atoi(argv[1]);
	steps = atoi(argv[2]);
	for(int j = 0; j < steps; ++j)
	{	
		printf("Proces potomny: %d\t krok: %d\n", i, j);
		sleep(1);
	}

	exit(i);
}
