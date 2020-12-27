#include <stdio.h>
#include <stdlib.h>
#include <string.h>      /* string handling functions */
#include <unistd.h>      /* header file for the POSIX API */
#include <time.h>        /* to write time */
#include <sys/types.h>   /* standard data types for systems programming */
#include <sys/file.h>    /* file-related system calls */
#include <sys/wait.h>    /* for wait() system call */ 
#include <signal.h>      /* signal handling calls */ 
#include <errno.h>       /* for perror() call */
#include <sys/ipc.h>     /* header file for SysV IPC */
#include <sys/shm.h>    /* shared memory calls */ 
#define BUFSZ 100

void zeroOutBuf(char *str) {
	int i;
	for (i=0; i < BUFSZ; i++)
		str[i] = 0;
}
int status;
 
int main(int argc, char *argv[]) {
	int logf; 
	int start = 0;
	char buf[100];
    int shmid;
    char pathname[128];
    getcwd(pathname,128);
    strcat(pathname,"/foo");    /* make sure file foo is in your directory*/
	int *shared_int;
	
	key_t ipckey = ftok(pathname, 21);
	int n = 0;
	char junk [10];
	
	
	shmid = shmget(ipckey, sizeof(int), IPC_CREAT | 0666);
	
	int *shared = shmat(shmid, (void *)0,0);
	logf= open ("log", O_WRONLY|O_CREAT | O_TRUNC, 0644);
	pid_t cpid;
	cpid=fork ();
	
	
	
	if (cpid == 0) { /* child  */
    while (*shared == 0)
	{
	}
	sprintf (buf, "received %d\n", *shared);
	write(logf, buf, strlen(buf));
	shmdt(shared);
	
	close (logf);
	exit (0);
	}
	else 
	{
		printf("shared address %p\n", shared );
		printf("enter a number: ");
		
		while ( ! scanf("%d", &n)){
			printf ("you must enter a number: ");
			scanf ("%10s", &junk);
	}
	*shared = n ;
	wait (&status);
	if (WIFEXITED (status))
	{
		sprintf (buf, "child exited with exit code %d\n", WEXITSTATUS(status));
		write (1, buf, strlen(buf));
		
		shmdt (shared);
		shmctl (shmid,IPC_RMID,0);
	}
}
}
