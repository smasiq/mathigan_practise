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
	dequeue (arr);
	dequeue (arr);
	display (arr);
	dequeue (arr);
	dequeue (arr);
	enqueue (arr);
	enqueue (arr);
	enqueue (arr);
	dequeue (arr);
	enqueue (arr);
	enqueue (arr);
	display (arr);

	return 0;
}

void enqueue (int *arr)
{
	if (rear == BUFF_SIZE -1)
	{
		printf ("Queue is full not able to insert new data, "
				"rear and front are reset to 0\n");
		//rear = -1;
		//front = -1;
		return ;
	}
	else
	{
		if (front == -1) {
			front = 0;
		}

		static int val = 0;
		val = val + 10;
		rear++;
		arr[rear] = val;
		printf ("enqueue %d element is inserted in queue\n",arr[rear]);
	}
}

void dequeue (int *arr)
{
	if (front == -1 || front > rear)
	{
		printf ("queue is empty no need to delete element from queue\n");
		return ;
	}
	else
	{
		printf ("dequeue %d element is removed from queue\n",arr[front]);
		front++;
	}
}

void display (int *arr)
{
	if (front == -1 || front > rear)
	{
		printf ("queue is empty not able to display from queue\n");
		return ;
	}
	else
	{
		printf ("Display elements from queue\n");
		for (int i=front; i<= rear;i++)
		{
			printf ("Queue elements %d\n",arr[i]);
		}
		printf ("\n");
	}
}
