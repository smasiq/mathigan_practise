#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd1[2]; // parent to child
    int fd2[2]; // child to parent

    pipe(fd1);
    pipe(fd2);

    pid_t pid = fork();

    if (pid == 0)
    {
		printf ("Child Process \n");
		getchar();
        // Child
        close(fd1[1]); // close unused write end of pipe1
        close(fd2[0]); // close unused read end of pipe2

        char msg[100];
        read(fd1[0], msg, sizeof(msg));
        printf("Child received: %s\n", msg);

        const char *reply = "Hi parent, got your message!";
        write(fd2[1], reply, strlen(reply) + 1);

        close(fd1[0]);
        close(fd2[1]);
    }
    else
    {
		printf ("Parent Process \n");
		getchar();
        // Parent
        close(fd1[0]); // close unused read end of pipe1
        close(fd2[1]); // close unused write end of pipe2

        const char *text = "Hello child, this is parent!";
        write(fd1[1], text, strlen(text) + 1);

        char buffer[100];
        read(fd2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(fd1[1]);
        close(fd2[0]);
    }

    return 0;
}
