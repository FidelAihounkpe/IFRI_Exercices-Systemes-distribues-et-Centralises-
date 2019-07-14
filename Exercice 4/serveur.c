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

#define MY_ADDR "127.0.0.1"
#define MY_PORT 56789
#define LISTEN_BACKLOG 50

int main(int argc, char *argv[]){
   int sfd; 
   int cfd; 
   struct sockaddr_in my_addr; 
   struct sockaddr_in peer_addr; 

   socklen_t peer_addr_size; 
   pid_t child;

   char buffer[10]; 

   sfd = socket(AF_INET, SOCK_STREAM, 0); 
   if (sfd < 0){ 
      printf("Le SE n'a pas pu créer la socket %d\n", sfd);
      exit(-1);
   }


   memset(&my_addr, 0, sizeof(struct sockaddr_in));
   
   
   my_addr.sin_family = AF_INET;
   my_addr.sin_port = htons (MY_PORT);
   inet_aton(MY_ADDR, (struct in_addr *)&my_addr.sin_addr.s_addr);
  

   if (bind(sfd, (struct sockaddr *) &my_addr,
                   sizeof(struct sockaddr_in)) < 0){
       printf("bind error\n"); 
       exit(-1);
  }


   if (listen(sfd, LISTEN_BACKLOG) < -1)
               perror("listen\n");


   peer_addr_size = sizeof(struct sockaddr_in);
   while(1){
         cfd = accept(sfd, (struct sockaddr *) &peer_addr,
                   &peer_addr_size);  
        if (cfd < 0){
            perror("accept\n");
            exit(-1); 
        }

        child = fork();
        if(child < 0){ 
           perror("errreur de création du fils\n");
        }
        if(child==0){
             
             printf("Nouveau client connecte ! Son identité du client : %d\n", peer_addr.sin_port);
             
             while(read(cfd, buffer, 10))
                 printf("%s", buffer);
             printf("\n");
             
             close(sfd);
             break;
        }

        else{
          
          close(cfd);
        }
  }
}
