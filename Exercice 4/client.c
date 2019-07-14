		/*	*********************************************************************************************************
										Auteur: AÏHOUNKPE Ulrich Fidel 
			*********************************************************************************************************		*/








#include <sys/socket.h>
#include <netinet/in.h>
 #include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define GREETING " \n Ulrich_Fidel se connecte au serveur ! (Veuillez patienter, Vous recevrez à nouveau ce message dans 10 secondes \n"
int main(int argc, char *argv[]){
	int it;
   int cfd; 
   int success; 
   int port;
   char v;
   struct sockaddr_in srv_addr;  

FILE* f=fopen("text.txt", "r+");
	
	
   if(argc!=3){
     printf("USAGE: ./client <serveur_ip_addr> <serveur_port>\n");
     exit(-1);
   }

   cfd = socket(AF_INET, SOCK_STREAM, 0); 
   if (cfd < 0){ 
      printf("Le SE n'a pas pu créer la socket %d\n", cfd);
      exit(-1);
   }

   port = atoi(argv[2]);

   srv_addr.sin_family = AF_INET;
   srv_addr.sin_port = htons (port);
   inet_aton(argv[1], (struct in_addr *)&srv_addr.sin_addr.s_addr);


   success = connect(cfd, (struct sockaddr *) &srv_addr,
                 sizeof(struct sockaddr_in));
   if(success < 0){ 
      printf("Impossible de se connecter au serveur %s:%d error %d\n", 
               argv[1], port, success);
      exit(-1);
   }

			do
				{
					v=fgetc(f);
					send(cfd, (char*) &v, sizeof(v), 0);
				}
			while(v!=EOF);


	/*for (it=0; it<10; it++)
		{

			sleep(10);
   			send(cfd, GREETING, sizeof(GREETING), 0);

			
			
		} */


   close(cfd);
   return(0);
}
