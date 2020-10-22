# 문제 2번 Error 수정하기 (25점)
다음 프로그램은 여러가지 Error를 담고 있다. 
solution02는 해당 코드가 정상적으로 동작하였을 시의 프로그램이며 이 결과를 참고하여 problem02.c를 수정하여 정상적으로 동작하도록 변경하라. 

## 참고사항
- 코드는 자유롭게 추가/삭제할 수 있음
- 종료하지 않는 프로그램은 Ctrl+C를 눌러 강제종료할 수 있음


```C
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
```
