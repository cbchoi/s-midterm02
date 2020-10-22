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