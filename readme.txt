			*********************************************************************************************************
										Auteur: AÏHOUNKPE Ulrich Fidel 
			*********************************************************************************************************



Réponses aux questions !

			*********************************************************************************************************
										Exercice 1:
			*********************************************************************************************************

			Voir code Exercice 1






			*********************************************************************************************************
										Exercice 2:
			*********************************************************************************************************

1- La valeur finale dans la mémoire partagée est 300

2- On peut résoudre ce problème grâce en verrouillant l'accès à la mémoire partagée lors de son utilisation par un processus. A la fin de son traitement, on déverrouille à nouveau la mémoire partagée.

3- Implémentation de la solution.
	(Voir codes Exercice 2)


2- Comment résoudre le problème:
	Il faudra verrouiller la mémoire partagée en créant une section critique au cours de laquelle seule le processsus ayant accès à la mémoire peut faire un traitement sur la mémoire. A la fin du traitement, on déverrouille la mémoire partagée pour qu'un autre processus puisse y avoir accès.




			*********************************************************************************************************
										Exercice 3:
			*********************************************************************************************************

1-  Les problèmes sont:
	Comment chaque processus qui calcule un Cij doit accéder à la matrice ?
	Dans quel ordre les processus doivent s'exécuter ?
	Comment initialiser la matrice ?
	Comment stocker les résultats des calculs dans la mémoire partagée ?
	Comment définir le processus qui remplit les valeurs entrées par l'utilisateur de la matrice ?
	Comment creer la matrice en mémoire

2- Approches de résolutions:
	Creer la mémoire partagée puis écrire la matrice dans un fichier. Faire accéder au fichier chaque le programme de lecture qui ira écrire dans la mémoire partagée.
	Ecrire une condition d'écriture sur les valeurs de la matrices pour que le processus qui veut écrire puisse savoir si elles sont déjà utilisées par un autre processus ou pas. 




			*********************************************************************************************************
											Exercice 4:
			*********************************************************************************************************
1- Les problèmes qu'on sera emmené à résoudre sont:
	-Paramétrage du client et du serveur
	-Déplacement du fichier vers le serveur
	-Reception du fichier sans lecture directe dans le terminal

2- Pour résoudre tous ces problèmes, il faudra écrire d'abord un fichier texte par exemple et passer en paramètre au client.  
	Le client l'enverra au serveur quand le code sera exécuté
	Le serveur le reçoit et l'affiche.

3- Implémentation de la solution.
	Ces solutions n'ont pas pu être implémentées



			*********************************************************************************************************
											Exercice 5:
			*********************************************************************************************************
	
1- Les problèmes qu'on sera emmené à résoudre sont:
	- Mise en attente du client pour envoi à chaque intervalle de temps (10 secondes) pour l'envoi des requêtes au serveur
	- Création des deux processus par le serveur et la modification de façon concurrente d'une valeur dans la mémoire partagée
	
2- Pour résoudre ces problème, il faudra creer une boucle "for" dans laquelle on fait un sleep(10) et le send()  pour faire l'envoi chaque 10 secondes.

3- Implémentation de la solution.
	(Voir codes dossier Exercice 5)
