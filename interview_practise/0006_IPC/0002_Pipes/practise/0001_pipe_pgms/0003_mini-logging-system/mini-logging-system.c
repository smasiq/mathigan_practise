#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main (void)
{
	int fd[2];
	int ret = 0;
	pid_t pid;

	ret = pipe(fd);
	if (ret == -1)
	{
		printf ("pipe syscall failed ret = %d\n",ret);
	}

	pid = fork();
	if (pid == 0)
	{
		close (fd[1]);
		char buff[100] = {0};
		//FILE * log_fd = fopen ("log.txt",O_CREAT|O_RDWR);
		// fopen() expects a mode string, not flags like O_CREAT | O_RDWR.
		// That’s for open() syscall.
		FILE * log_fd = fopen ("log.txt","w");
		if (log_fd < 0)
		{
			printf ("fopen failed \n");
		}
		//read (fd[0],buff,sizeof(buff));
		//fprintf (log_buff,buff);
		while (1)
		{
			memset(buff, 0, sizeof(buff));
			ssize_t n = read(fd[0], buff, sizeof(buff) - 1);
			if (n <= 0)
				break;

			fprintf(log_fd, "%s\n", buff);
			fflush(log_fd);
		}
		fclose (log_fd);
		close (fd[0]);
	}
	else
	{
		close (fd[0]);
		char *message[] = { "Event 1: Sensor ON",
							"Event 2: Sensor OFF",
							"Event 3: Temp is 37 F",
							"Event 4: LED blinks RED",
							"Event 5: LED blinks GREEN",
		};

		int i=0;
		while (i < 5)
		{
			//write (fd[1],message[i],strlen(message[i])+1); //+1 includes the null terminator. 
			// but here is bug like we have multiple message every message transmit through single pipe at a time.
			// and every message ends with null, So kernel buffer stops read every null character
			// it reflect in output file some logs not save properly (string truncation happen),
			// So don't need null for every log instead of add \n (new line) or some other delimiter
			write (fd[1],message[i],strlen(message[i])); 
			write(fd[1], "\n", 1);
			i++;
		}
		close (fd[1]);
		wait (NULL);
	}
	return 0;
}
