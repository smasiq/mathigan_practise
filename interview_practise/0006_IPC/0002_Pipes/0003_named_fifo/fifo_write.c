#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (void)
{
	mkfifo("myfifo", 0666);  // create FIFO if not exists

    int fd = open("myfifo", O_WRONLY);
    const char *text = "Hello from writer process!";
    write(fd, text, strlen(text) + 1);
    printf ("Writing Done ...\n");
	getchar();
    close(fd);
    return 0;
}
