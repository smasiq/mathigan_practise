#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *td_func (void *);

void *td_func (void *data)
{
	printf ("before modifing %s\n",(char *)data);
	strcpy ((char*)data, "Good morning..");
	return (char *)data;
}

int main (void)
{
	pthread_t tid;
	pthread_attr_t attr;
	int ret = 0;
	char buffer[50] = {0};
	void * ret_data = buffer;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_setstacksize(&attr, 1024*1024);

	strcpy ((char *)ret_data, "Hello_world");

	ret = pthread_create (&tid,&attr,td_func,ret_data);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}
    sleep (1);
	ret = pthread_attr_destroy(&attr);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}
#if 0
	ret = pthread_join (tid,NULL);
	if (ret != 0)
	{
		printf ("Line : %d pthread join failed ret = %d\n",__LINE__,ret);
	}
#endif
	/*
	 * If thread state is detatched state means it terminate thread no
	 * need to call pthread_join, If call
	 * it fails with EINVAL because detached threads cannot be joined;
	 * their resources are automatically released when they exit.
	 *
	 * */
    printf ("after modifing ret_data  %s\n",(char *)ret_data);
	return 0;
}
