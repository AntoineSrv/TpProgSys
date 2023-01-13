#include "fonction.h"


int main() {
	int nbChar;
	int status;
	char commande[MAXSIZE];
	
	accueil();
	while(1){
		
		nbChar = read(STDIN_FILENO, commande, MAXSIZE);
		commande[nbChar-1] = '\0';
		
		if(strcmp(commande, "exit")==0 || strcmp(commande,"")==0){
			endProg();
			}
		
		pid_t ret= fork();
		if (ret==0){
			execut(commande);
		}
		
		else {
			wait(&status);
			writeEnsea();
			if (WIFEXITED(status) != -1){
				afficherCode("[code exit: %d]\t",WEXITSTATUS(status));
				}
			else if (WIFSIGNALED(status)){
				afficherCode("[signal exit: %d]\t", WTERMSIG(status));
				}
		}	
	}
}

