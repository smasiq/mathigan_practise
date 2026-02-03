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

	strcpy ((char *)ret_data, "Hello_world");

	ret = pthread_create (&tid,NULL,td_func,ret_data);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}
	//sleep (2); 
    //printf ("after modifing ret_data %s\n",(char *)ret_data);
	ret = pthread_join (tid,NULL);
	if (ret != 0)
	{
		printf ("Line : %d pthread creation failed ret = %d\n",__LINE__,ret);
	}
    printf ("after modifing ret_data-1 %s\n",(char *)ret_data);
	return 0;
}
