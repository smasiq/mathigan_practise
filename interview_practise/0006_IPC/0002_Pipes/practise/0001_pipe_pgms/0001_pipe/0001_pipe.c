/*
 * Qn-1 A program that passes data between the two
 * halves of a forked process using pipe.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


int main (void)
{
	int fd[2];
	int ret = 0;
    pid_t pid;

	ret = pipe (fd);
	if ( ret < 0)
	{
		printf ("pipe get failed ret %d\n", ret);
	}
 
    pid = fork();
	if (pid == 0)
	{
		close (fd[0]);
		printf ("Child process pid = %d\n",getpid());
		char *text = "Hi Parent , I am child process";
		write (fd[1],text, strlen(text));
		close (fd[1]);
	}
	else
	{
		close (fd[1]);
		printf ("Parent process pid = %d\n",getpid());
		getchar();
		char buff[100];
		read (fd[0],buff, sizeof(buff));
		printf ("Parent received message from child\n");
		printf ("message is %s\n",buff);
		close (fd[0]);
		wait (NULL);
	}
	return 0;
}
