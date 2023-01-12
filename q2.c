#include "fonction.h"

void main() {
	
		int status;
		int nbChar;
		char commande[MAXSIZE];
		
		nbChar = read(STDIN_FILENO, commande, MAXSIZE);
		commande[nbChar-1] = '\0';
		
		pid_t ret= fork();
		
		if (ret==0){
			
			execlp(commande,commande, NULL);
			exit(EXIT_FAILURE);
		}
		else {
			wait(&status);
			write(STDOUT_FILENO, msg_enseash, strlen(msg_enseash));
		}	
}
