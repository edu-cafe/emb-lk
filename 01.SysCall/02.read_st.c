#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct _INFO {
	char name[20];
	int age;
	float height;
} INFO;

int main(int argc, char *argv[])
{
	INFO *data;
	int fd;
	struct stat fileinfo;
	int file_size, data_no;
	int i;

	if((.......))==-1)
	{
		perror("open");
		exit(1);
	}

	............

	if((data = (INFO *)malloc(sizeof(INFO) * data_no)) == NULL) {
		perror("malloc");
		close(fd);
		exit(2);
	}

	if(............) {
		perror("read");
		close(fd);
		exit(3);
	}

	for(i=0; i<data_no; i++)
	{
		printf("name:%s, age:%d, height:%.1f\n", data[i].name, data[i].age, data[i].height);
	}

	close(fd);
	return 0;
}
