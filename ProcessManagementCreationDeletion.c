#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		fprintf(stderr,"Failed to create");
		exit(1);
	}else if(pid==0){
		execlp("/bin/ls","ls",NULL);
		fprintf(stderr,"Failed Child Process");
	}else{
		wait(NULL);
		printf("Child Process Completed It's Execution");
	}
}
