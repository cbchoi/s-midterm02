# 문제 1번 코드 설명 (10점)
다음은 fork와 pipe를 사용한 프로그램의 예제이다. 
fork와 pipe에 대한 설명을 다음 코드를 사용하여 설명하시오. 

## 참고사항
- 반드시 주어진 코드를 사용하여 의미를 설명해야 함. 
- 단순 fork, pipe에 대한 설명은 3점
- 주어진 코드와 코드에 대한 의미를 풀어서 설명한 경우 7점


```C
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

struct my_msg
{
	int data1;
	int data2;
};

int main()
{
	pid_t pid;
	int pfd[2];
	
	int status;
	char* buff = malloc(sizeof(struct my_msg));

	if(pipe(pfd) < 0)
	{
		perror("pipe()");
		return -1;
	}

	if((pid = fork()) < 0)
	{
		perror("fork()");
		return -1;
	}
	else if(pid == 0)
	{
		struct my_msg _var;
		_var.data1 = 10;
		_var.data2 = 20;

		printf("%s: data1:%d data2:%d\n", "Child Process", 
			_var.data1, _var.data2);
		write(pfd[1], &_var, sizeof(struct my_msg));
		
	}
	else
	{
		struct my_msg _var;
		_var.data1 = -1;
		_var.data2 = -1;

		printf("%s: data1:%d data2:%d\n", "Parent Process", 
			_var.data1, _var.data2);
		read(pfd[0], &_var, sizeof(struct my_msg));
			printf("%s: data1:%d data2:%d\n", "After receiving msg from Child Process", 
			_var.data1, _var.data2);
	}

	free(buff);
	return 0;
}
```
