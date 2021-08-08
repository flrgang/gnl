#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd = /*open("test.txt",O_RDONLY);*/ 1000;
	printf("%d\n",fd);
	char* str = read_nl(fd);
	//read the string:
	printf("read the string:%s\n", str);
	close(fd);
	free(str);
	return 0;
}
