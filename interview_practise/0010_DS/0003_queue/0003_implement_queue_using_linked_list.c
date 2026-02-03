#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}queue;

void enqueue (queue **, queue **);
void dequeue (queue **);
void display (queue *);

int main (void)
{
	queue *front = NULL, *rear = NULL;

	enqueue (&front, &rear);
	enqueue (&front, &rear);
	enqueue (&front, &rear);
	dequeue (&front);
	display (front);

	return 0;
}

void enqueue (queue **front, queue **rear)
{
     queue *newnode = NULL;
	 static int val = 0;

	 newnode = (queue *) malloc (sizeof(queue));
	 if (newnode == NULL)
	 {
		 printf ("From %d:%s func malloc failed\n",__LINE__,__func__);
		 exit (EXIT_FAILURE);
	 }
	 val = val + 10;
	 newnode->data = val;
	 newnode->next = NULL;

	 if (*front == NULL)
	 {
		 *front = newnode;
	 }
	 else
	 {
		 (*rear)->next = newnode;
	 }
	 *rear = newnode;
	 printf ("Enqueue element %d to queue\n",(*rear)->data);
}

void dequeue (queue **front)
{
	if (*front == NULL)
	{
		printf ("Queue is empty\n");
		return ;
	}
	else
	{
		queue *temp = *front;
		*front = (*front)->next;
		printf ("Dequeue element %d from queue\n",temp->data);
		free (temp);
	}
}

void display (queue *front)
{
	if (front == NULL)
	{
		printf ("Queue is empty\n");
		return ;
	}
	else
	{
		queue *temp = front;
		while (temp != NULL)
		{
			printf ("Queue element %d\n",temp->data);
			temp = temp->next;
		}
	}
}
