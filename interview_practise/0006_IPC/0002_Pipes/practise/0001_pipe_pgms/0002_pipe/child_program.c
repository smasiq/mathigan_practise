#include <stdio.h>
#include <unistd.h>

//extern int read_fd;

int main (void)
{
	char buff [100] = {0};
    //printf ("read FD for child process %d\n",read_fd);
    printf ("read FD for child process\n");

	read (STDIN_FILENO,buff,sizeof(buff));
	printf ("Message recieved from parent process pid %d\n",getppid());
	printf ("%s\n",buff);
	return 0;
}
