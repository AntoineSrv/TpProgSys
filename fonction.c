#include "fonction.h"


void accueil() {
	
	write(STDOUT_FILENO, msg_bienvenue, strlen(msg_bienvenue));
	write(STDOUT_FILENO, msg_enseash, strlen(msg_enseash));
}

void endProg(){
	write(STDOUT_FILENO, msg_exit, strlen(msg_exit));
	exit(EXIT_SUCCESS);
}

void writeEnsea(){
	write(STDOUT_FILENO, msg_enseash, strlen(msg_enseash));
}

void execut(char commande[MAXSIZE]){
	execlp(commande,commande, NULL);
	exit(EXIT_FAILURE);
}

void afficherCode(char *text, int val){	//en entrée le text du code à afficher et sa valeur
	char buff[MAXSIZE];
	sprintf(buff,text, val);
	write(STDOUT_FILENO, buff, strlen(buff));
}
