/** 
  * Qn - 2 :
  * A program that uses the functions fork and
  * execl to create a child process and then
  * uses the function pipe to pass data from
  * one to the other.
  * 
  */
  
#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>

//int read_fd = 0;

int main (void) 
{
	int fd[2]; 
	pid_t pid; 
	int ret = 0; 

	ret = pipe(fd); 
	if (ret == -1) 
	{ 
		printf ("pipe called failed ret %d\n",ret); 
		return ret;
	} 

	pid = fork();

	if (pid == 0) 
	{
		char *argv[] = {"./child_program", NULL}; 
		close (fd[1]);
		// read_fd = fd[0]; 
		// global variable not work bcz
		// execve replace entire process it create new VAS 
		// new code, data,text, stack segments 
		// So we loss read_fd data
		// but fd[0] handle by kernel so it won't loss 
		// with that we can pass FD using dup2 system call 
		dup2 (fd[0],STDIN_FILENO);
		/*
		 *  What dup2() does
		 *  dup2(oldfd, newfd) is a system call that:
		 *	  Closes newfd if it’s already open.
		 *	  Makes newfd refer to the same open file description as oldfd
		 *
		 *   Here, fd[0] → read-end of the pipe
		 *    STDIN_FILENO → standard input (normally file descriptor 0)
		 *    After this, when the child calls read(0, ...) or scanf(), it actually reads from the pipe, not the keyboard.
		 * */
		close (fd[0]); 
		execve("./child_program", argv, NULL);
		printf ("execve failed\n");
        return 1;
	}
	else 
	{ 
		close (fd[0]); 
		char *text = "Hello child, I'm parent process"; 
		printf ("Parent process invoke, pid = %d\n",getpid()); 
		write (fd[1],text, strlen(text));
		close (fd[1]);
		wait (NULL);
		/*
		 * If you comment wait you observe
		 * after parent finish it not wait for child terminate 
		 * before child terminate parent will exit.
		 * */
	}
	return 0;
}
