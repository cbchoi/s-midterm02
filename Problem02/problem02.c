#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <signal.h>

#include <sys/wait.h>

void sigHandler(int signo)
{
	if(signo == SIGCHLD)
	{
		printf("%s\n", "Termination of the Child Process Detected!");
	}
}

int main()
{
	pid_t pid;
	int var = 20;
	
	if((pid = fork()) < 0)
	{
		printf("%s\n", "ERROR : fork()");
	}
	else if(pid == 0)
	{
		printf("\nChild Process\n");
		printf("PID: %d\n", pid);
		printf("var: %d\n", var);
		sleep(2);
	}
	else
	{
		int status;
		int var = 30;
		printf("\nParent Process\n");
		printf("PID: %d\n", pid);
		printf("var: %d\n", var);
		
	}
	return 0;
}