#include <stdio.h>
#include <pthread.h>
#include <sys/syscall.h>
#include <unistd.h>

void * td_func (void *);

void * td_func (void *data)
{
	printf ("hello %s thread function thread id %ld\n",__func__,pthread_self());
	/*
	 * pthread_self() returns a pthread_t, which is not the same as LWP, but represents the thread inside the POSIX pthread library.
	 * On Linux, pthread_t is often an unsigned long pointing to thread control block, not the LWP ID.
	 * That’s why pthread_self() prints something like 137942743905984, while ps -Lf shows LWP 16613.
	 * Key point:
	 *    pthread_t → thread identifier for programmatic use in C (POSIX threads)
	 *    LWP → kernel-level thread ID visible in ps
	 */
	pid_t tid = syscall(SYS_gettid);
	printf("Linux thread ID (LWP): %d\n", tid);
   // pthread_self() gives a thread handle, not the system-visible thread ID.
   // Use syscall(SYS_gettid) to get the LWP from inside your thread.
	getchar();
	return (void *) NULL;
}

int main (void)
{
	pthread_t tid;
	int ret = 0;

	ret = pthread_create (&tid,NULL,td_func,NULL);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}

	ret = pthread_join (tid,NULL);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}

	return 0;
}
