#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

static int  semid;

void p()
{
   struct sembuf pbuf;

   pbuf.sem_num   = 0;
   pbuf.sem_op    = -1;
   pbuf.sem_flg   = SEM_UNDO;

   if ( -1 == semop(semid, &pbuf, 1))
      printf( "p()-semop() error!\n");
}

void v()
{
   struct sembuf vbuf;

   vbuf.sem_num   = 0;
   vbuf.sem_op    = 1;
   vbuf.sem_flg   = SEM_UNDO;

   if ( -1 == semop( semid, &vbuf, 1))
      printf( "v()-semop() error!\n");
}

int main(int argc, char **argv) { 
	void *shmaddr;
	struct shmid_ds shm_stat;
	int i,j;
	int shmid;
	union senum {
		int val;
		struct semid_ds *buf;
		unsigned short int *array;
	} sem_ctrl;
	//struct sembuf sem_ops;

	if(argc!=2) {
		fprintf(stderr, "Usage : myshmtest1 shmkey\n");
		exit(1);
	}

	printf("mysem2 is started.......\n");

	if((shmid=shmget((key_t)atoi(argv[1]),128, IPC_CREAT|0666)) == -1 )  {
		perror("shmget failed !!");         
		exit(1);
	}
	if((semid=semget((key_t) 0x1234, 1, IPC_CREAT|0666)) == -1 )  {
		perror("shmget failed !!");         
		exit(1);
	}

#if 0
	sem_ctrl.val = 1;
	if(semctl(semid, 0, SETVAL, sem_ctrl) == -1) {
		perror("semctl");
		exit(1);
	}
#endif

	if((shmaddr=shmat(shmid,(void *)0,0))==(void *)-1) {
		perror("shmat failed !!");        
		exit(1);
	}

	for(i=0;i<500;i++) {
#ifndef NOSEM
		p();
#endif

		sprintf((char *) shmaddr,"%d", getpid());
		for(j=0; j<500000; j++);
		if(getpid() == atoi(shmaddr))
			putchar('O');
		else
			putchar('X');
		fflush(stdout);

#ifndef NOSEM
		v();
#endif
	}

	if(shmdt(shmaddr)  == -1) {
		perror("shmdt failed !!");        
		exit(1);
	}
	printf("myssem2 is end!!\n");
	exit(0);
}

