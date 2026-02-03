#include <stdio.h>
#define BUFF_SIZE 5

void enqueue (int *);
void dequeue (int *);
void display (int *);

int rear = -1, front = -1;

int main (void)
{
	int arr[BUFF_SIZE];

	enqueue (arr);
	enqueue (arr);
	enqueue (arr);
	enqueue (arr);
	enqueue (arr);
	dequeue (arr);
	display (arr);
	enqueue (arr);
	dequeue (arr);
	display (arr);

	return 0;
}

void enqueue (int *arr)
{
	if (rear == BUFF_SIZE -1 && rear == front+1)
	{
		printf ("Queue is full not able to insert new data, "
				"rear and front are reset to 0\n");
		return ;
	}
	else
	{
		if (front == -1) {
			front = 0;
		}

		static int val = 0;
		val = val + 10;
		//rear++;
		rear = (rear + 1) % BUFF_SIZE;
		arr[rear] = val;
		printf ("enqueue %d element is inserted in queue\n",arr[rear]);
	}
}

void dequeue (int *arr)
{
	//if (front == -1 || front > rear ) // it work in linear queue
	// but in circular queue rear value will be move to 0 after reach max
	// buffer value , So here front > rear no need.
	if (front == -1)
	{
		printf ("queue is empty no need to delete element from queue\n");
		return ;
	}
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		printf ("dequeue %d element is removed from queue\n",arr[front]);
		//front++;
		front = (front + 1) % BUFF_SIZE;
	}
}

void display (int *arr)
{
	if (front == -1 )
	{
		printf ("queue is empty not able to display from queue\n");
		return ;
	}
	else
	{
		printf ("Display elements from queue\n");
		for (int i=front; /*i != rear */;i = (i+1) % BUFF_SIZE)
		{
			printf ("Queue elements %d\n",arr[i]);
			if ( i == rear)
				break;
		}
		/* 
		 *  why commentinf i != rear means it not print last element 
		 *  if need to print copy line 86 to outside of loop
		 *  then print. 
		 * */
		printf ("\n");
	}
}
