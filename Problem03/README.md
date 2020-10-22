# 문제 3번 디렉토리 구조체 활용하기
다음 코드는 search_files 함수에서 주어진 경로(path)에 존재하는 모든 파일 속에서 주어진 값(key)을 갖고 있는 모든 파일을 찾는 프로그램이다. 

힌트 코드를 참고하여 프로그램이 정상적으로 동작하도록 구현하시오. 

## 참고사항
 - 코드는 자유롭게 추가/삭제할 수 있음
 - Compile Error: 0점
 - Compile은 성공하였으나 Runtime Error 발생: 5점
 - Compile은 성공하였고 Runtime Error가 발생하지 않으나 원하는 결과를 도출하지 않는 경우: 15점
 - Compile 성공, 원하는 결과 도출: 25점

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define KEY_SIZE 3

void search_files(char* path, char* key)
{
	/** 
	 Hint Code

	 int ret = snprintf(pbuf, 255, "%s/%s", path, dir->d_name);

	 if(strcmp(buff, key) == 0)
	 {
		printf("File Name:%s\n", dir->d_name);
		count++;
	 }
	*/

	printf("Total %d files are found.\n", count);
}

int main()
{
	search_files("./data", "abc");
	return 0;
}
```
