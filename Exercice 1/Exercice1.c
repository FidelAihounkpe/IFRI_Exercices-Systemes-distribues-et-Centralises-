		/*	*********************************************************************************************************
										Auteur: AÏHOUNKPE Ulrich Fidel 
			*********************************************************************************************************		*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

	int main ()
	{
	int i, n=3;
	
	for ( i=1; i<n; i++)
	{
	fork();

	/*if (fork()==0)
	{
	printf (" Affichage des trois processus : pid1: %d pid2 %d pid3: %d\n", getpid(), getpid(), getpid() );
	} */
	}

	if (fork()==0)
	{
	printf (" Affichage des trois processus fils : pid1: %d pid2 %d pid3: %d\n", getpid(), getpid(), getpid() );
	}

		return 0;
	}
