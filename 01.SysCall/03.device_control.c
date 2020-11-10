#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char data1[100] = "Hello, Kim!!\n";
	char data2[100] = "Hi, Lee~~\n";
	int fd;

	if((fd=open(argv[1], O_WRONLY|O_CREAT))==-1)
	{
		perror("open");
		exit(1);
	}
	if(write(fd, &data1, strlen(data1)) != strlen(data1)) {
		perror("write1");
		close(fd);
		exit(2);
	}
	if(write(fd, &data2, strlen(data2)) != strlen(data2)) {
		perror("write2");
		close(fd);
		exit(2);
	}
	close(fd);
	return 0;
}
