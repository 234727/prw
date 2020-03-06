#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>

// ********* ZADANIE 1 *************************
// procesy za pomoca fork, ten sam program
// -------------- 1 ----------------------------
// macierzysty utworzayc  n procesow potomnych 
// n = argc - 2
// procesy tworzymy w petli 
// -------------- 2 ---------------------------
// macierzysty wypisuje "macierzysty krok_x
// --------------- 3 --------------------------
// macierzysty czeka na potomne, wypisuje pid procesu, ststus zakoczenia 

// ***************** ZADANIE 2 *****************
// to samo co wyzej, z tym ze przenosimy KOD POTOMNEGO  do innego pliku 
// przekazanie parametrow - nr potomentgo; liczba krokow 
// w konsoli odpalamy ./program num kroki (argumenty) - testowanie 
// w macierzystym uzywamy exec("./program, "program", numer, kroki, NULL) // pamietac o zamianie int na string itoa lub spritf

//**************** ZADANIE 3 ******************
// wszystko to samo, tylko uzywamy polecenia SYSTEM 
#define MAX 20
void main(int argc, char *argv[])
{
	int counter = argc - 2;
	int pid[MAX], status[counter], steps_m = 0;
	int max_steps = atoi(argv[1]);

	for(int i = 0; i < counter; ++i)
	{
		if((pid[i] = fork()) == 0) 
		{
			int steps = atoi(argv[i+2]);
			for(int j = 0; j < steps; ++j)
			{
				printf("Potomny %d \t krok: %d \n", i+1, j);	
				sleep(1);
			}
			exit(i+1);
		}
	}
	
	printf("Macierzysty pid: %d \n", getpid());
    for(int i = 0; i < max_steps; ++i) {
		printf("Macierzysty krok: %d \n", i);
        sleep(1);
    } 

	for(int i = 0; i < counter; ++i) {
		pid[i] = wait(&status[i]);
		printf("Proces %d zakonczony status: %d\n", pid[i], WEXITSTATUS(status[i]));
   }

}
