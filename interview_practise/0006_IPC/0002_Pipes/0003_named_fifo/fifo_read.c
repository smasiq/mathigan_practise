#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
//#include <string.h>

int main (void)
{
	mkfifo("myfifo", 0666);  // create FIFO if not exists

    //int fd = open("myfifo", O_RDONLY|O_NONBLOCK);
    int fd = open("myfifo", O_RDONLY);
    //const char *text = "Hello from writer process!";
	char text[100];
    //read (fd, text, strlen(text) + 1);
    read (fd, text, sizeof(text));
    printf ("Read recieved : %s\n",text);
    close(fd);
    return 0;
}
