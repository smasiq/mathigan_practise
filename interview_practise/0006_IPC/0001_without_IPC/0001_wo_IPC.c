#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int value = 10;

    pid_t pid = fork();

    if (pid == 0)
    {
		pid_t cpid = getpid();   // get current process ID
        
        // Child processi
        printf("Child: initial value = %d child process id = %d\n", value,cpid);
        value = 20;
        printf("Child: changed value = %d child process id = %d\n", value,cpid);
    }
    else
    {
		pid_t ppid = getpid();

		printf (" parent process id %d waiting for finish child process\n",ppid);
        // Parent process
        sleep(1); // wait for child to finish
        printf("Parent: value = %d parent process id = %d\n", value,ppid);

		// parent process not seeing when child process change 
		// value variable to 20.
    }

    return 0;
}
