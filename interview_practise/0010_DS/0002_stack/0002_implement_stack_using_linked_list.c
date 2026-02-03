#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

void push (node **);
void pop (node **);
void display (node *);


int main (void)
{
	node *head = NULL;

	push(&head);
	push(&head);
	push(&head);
	pop(&head);
	display(head);
	push(&head);
	push(&head);
	push(&head);
	push(&head);
	pop(&head);
	display(head);
	push(&head);
	push(&head);
	display(head);

	return 0;
}

void push (node **head)
{
	node *newnode = (node *) malloc (sizeof (node));
	static int val = 0;

	if (newnode == NULL)
	{
		printf ("From %d:%s func malloc failed\n",__LINE__,__func__);
		exit (EXIT_FAILURE);
	}

	val = val+10;
	newnode->data = val;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
	printf ("PUSH %d element to stack\n",(*head)->data);
}

void pop (node **head)
{
	if (*head == NULL)
	{
		printf ("Stack is empty, So POP not happen\n");
		return ;
	}
	else
	{
		node *temp = NULL;
	
	    if ( (*head)->next == NULL)
		{
			free (*head);
		}
		else
		{
			temp = *head;
			*head = temp->next;
			printf ("POP %d element from stack\n",temp->data);
			free (temp);
		}
	}
}

void display (node *head)
{
	if (head == NULL)
	{
		printf ("From %s func, Stack is empty\n",__func__);
		return ;
	}
	else
	{
		//while (head->next != NULL)
		printf ("Display stack elements are\n");
		while (head != NULL)
		{
			printf ("Stack element is %d\n",head->data);
			head = head->next;
		}
		printf ("\n");
	}
}
