#include <sys/shm.h>
#include <stdio.h>
#include <sys/ipc.h>  // ftok()
#include <stdlib.h>

int main (void)
{
#if 0
    key_t key = ftok("shmfile", 65);
	// key is used to get b
    int shmid = shmget(10, 1024, 0666);   // Get same segment
    char *str = (char *) shmat(shmid, NULL, 0);  // Attach
#endif
    //printf("Data read from memory: %s\n", str);
	FILE *fp = fopen("shmfile", "w");
	if (fp == NULL) {
        perror("fopen failed");
        exit(1);
    }
    key_t key = ftok("shmfile", 65);
    //int shmid = shmget(key, 1024, 0666);   // Get same segment
	// without IPC_CREATE kernel can't create share mem.
	// So this process face seg fault , If that share mem already not exist.
	// If already share mem present no need include flag and seg fault not 
	// happen.

    //int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	
	int shmid = shmget(10, 1024, 0666 | IPC_CREAT);
	// else without ftok you can hardcode key
	// value in unsigned int between 0 - 255
	// check size don't exceed max value 
	// (Refer in ../notes.txt file about max values)
	// else get seg fault
	// we can increase max value (using mmap or some other modify config using sysctl)

	printf ("key value : %d shmid : %d\n",key,shmid);
    char *str = (char *) shmat(shmid, NULL, 0);  // Attach
	printf("Write Data : ");
    fgets(str, 1024, stdin);   // Write input to shared memory

    printf("Data written in memory: %s\n", str);

    //getchar();
    //shmdt(str);   // Detach
    //shmctl(shmid, IPC_RMID, NULL);   // Destroy shared memory
	
	return 0;
}
