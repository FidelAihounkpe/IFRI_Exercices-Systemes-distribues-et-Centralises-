		/*	*********************************************************************************************************
										Auteur: AÏHOUNKPE Ulrich Fidel 
			*********************************************************************************************************		*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>

#define ITER 100

	int main(int argc, char *argv[])
		{
    			pid_t pid1, pid2, pid3; 
    			int i,a=0 ;
    			key_t key = ftok("shmfile",65);               
    			int shmid = shmget(key,1024,0666|IPC_CREAT);

     			char *str = (char*) shmat(shmid,(void*)0,0);
     			sprintf(str, "%d", a);                           

     			pid1 = fork();
    				if(pid1 < 0)
    					{
          					perror("Erreur lors de la création du processus 1\n");
          						exit(EXIT_FAILURE);
    					}

    				if(pid1>0)

    				{ 
				printf("Creation du processus 1 ! \n");

      					for (i=0 ; i < ITER; i++ )
      						{
         						a++ ;
         						sprintf(str, "%d", a); 
      						}

     				printf("La valeur finale apres incrementation du processus 1 est  :%s \n\n" ,str);
      					pid2 = fork();
      					if(pid2 < 0)
      						{
      							perror("Erreur lors de la création du processus 2 \n");
      							exit(EXIT_FAILURE);
      						}

      				if(pid2>0)
      				{    
					printf("Creation du processus 2 !\n");

      					for (i=0 ; i < ITER; i++ )
      						{
         						a++ ;
         						sprintf(str, "%d", a); 
      						}

     							printf("La valeur finale apres incrementation du processus 2 est  :%s \n\n" ,str);
          				pid3 = fork();
            					if(pid3 < 0)
            						{
              							perror("Erreur lors de la création du processus 3 \n");
              							exit(EXIT_FAILURE);
            						}

           					if(pid3>0)
            						{    
								printf("Creation du processus 3 ! \n");

      								for (i=0 ; i < ITER; i++ )
      									{
         									a++ ;
        									sprintf(str, "%d", a); 
      									}

     								printf("La valeur finale apres incrementation du processus 3 est  :%s \n\n" ,str);


                				printf(" Le pid du  processus  1 est : %d\n", pid1);
                				printf(" Le pid du  processus  2 est : %d\n", pid2);
                				printf(" Le pid du  processus  1 est : %d\n",pid3);
            }
        }
    }
 			shmdt(str);
 			shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
