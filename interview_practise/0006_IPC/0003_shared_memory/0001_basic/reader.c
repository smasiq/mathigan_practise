#include <sys/shm.h>
#include <stdio.h>
#include <sys/ipc.h>  // ftok()

int main (void)
{
    key_t key = ftok("shmfile", 65);
	// key is used to get b
    //int shmid = shmget(key, 1024, 0666);   // Get same segment
    int shmid = shmget(10, 1024, 0666 | IPC_CREAT);   // Get same segment
	printf ("shmid :%d\n",shmid);
    char *str = (char *) shmat(shmid, NULL, 0);  // Attach

    printf("Data read from memory: %s\n", str);
   
    //getchar();
    //shmdt(str);   // Detach
    shmctl(shmid, IPC_RMID, NULL);   // Destroy shared memory
	
	return 0;
}
