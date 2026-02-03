#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>  // for wait()

int main(void)
{
	//  pid_t pid = fork();  
	//  don't call fork before call pipe.
	//  else each process both parent and child has own file descriptor and own pipe buffer.
	//  hence it not have common pipe so can't communicate b/w parent and child process
	//  always call pipe before fork (), this ensures both parent and child share 
	//  the same pipe and duplicate file descriptors to child from parent process.
	//  ls -al /proc/17749<pid>/fd/ using this we can see pipe file descriptors.
	//  when call fork before and after pipe()
	
	int fd[2];
	int ret = 0;

    //pid_t pid = fork();
	ret = pipe (fd);
	if ( ret == -1)
	{
		perror ("pipe get failed\n");
		return -1;
	}

    pid_t pid = fork();

	if (pid == 0)
	{
		getchar();
		// Child process
        close(fd[1]);  // close write end

        char msg[100];
        read(fd[0], msg, sizeof(msg));
        printf("Child received: %s\n", msg);
       // fflush(stdout);  // ensure output appears
        close(fd[0]);
	}
	else
	{
		getchar();
		printf ("parent process\n");
		// Parent process
        close(fd[0]);  // close read end

        const char *text = "Hello from parent!";
        write(fd[1], text, strlen(text) + 1);

        close(fd[1]);
		wait (NULL);
	}
}
