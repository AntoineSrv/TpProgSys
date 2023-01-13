#include "fonction.h"


int main() {
	int nbChar;
	int status;
	char commande[MAXSIZE];
	struct timespec timeStart, timeStop;
	accueil();
	while(1){
		
		nbChar = read(STDIN_FILENO, commande, MAXSIZE);
		commande[nbChar-1] = '\0';

		endProg(commande);
		clock_gettime(CLOCK_REALTIME, &timeStart);		
		pid_t ret= fork();
		if (ret==0){
			executPipe(commande);
		}
		
		else {
			wait(&status);
			clock_gettime(CLOCK_REALTIME, &timeStop);
			writeEnsea();
			if (WIFEXITED(status)){
				afficherCode("[code exit: %d | ",WEXITSTATUS(status));
				afficherCode("%ld ms] ", (timeStop.tv_nsec - timeStart.tv_nsec)/ConvNsToMs);
				}
			else if (WIFSIGNALED(status)){
				afficherCode("[signal exit: %d | ", WTERMSIG(status));
				afficherCode("%ld ms] ", (timeStop.tv_nsec - timeStart.tv_nsec)/ConvNsToMs);
				}
		}	
	}
}

