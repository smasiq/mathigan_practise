#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void create_node (node **, node **);
void display (node *);
void move_last_node_to_head (node **, node **);

void move_last_node_to_head (node **head, node **tail)
{
	if (*head == NULL)
	{
		printf ("Given linked list is empty\n");
		return ;
	}
	else
	{
		node *trav = *head;

		while (trav->next != *tail)
		{
			trav = trav->next;
		}
		(*tail)->next = *head;
		*head = *tail;
		*tail = trav;
		(*tail)->next = NULL;
	}
}

void display (node *trav)
{
	if (trav == NULL)
	{
		printf ("Given linked list is empty\n");
		return ;
	}
	else
	{
		while (trav != NULL)
		{
			printf ("data : %d\n",trav->data);
			trav = trav->next;
		}
	}
}

void create_node (node **head, node **tail)
{
	node *newnode = NULL;
	static int val = 0;

	newnode = (node *) malloc (sizeof(node)) ;
	if (newnode == NULL) 
	{
		printf ("From %d:%s func malloc failed\n",__LINE__,__func__);
		exit (EXIT_FAILURE);
	}

	val = val + 10;
	newnode->data = val;
	newnode->next = NULL;

	if (*head == NULL) 
	{
		*head = newnode;
	}
	else
	{
		(*tail)->next = newnode;
	}
	*tail = newnode;
}

int main (void)
{
	node *head = NULL, *tail = NULL;

	for (int i=0; i<5; i++)
	{
		create_node (&head, &tail);
	}
	display (head);
	move_last_node_to_head (&head, &tail);
	printf ("After move last node to head position linked list display as\n");
	display (head);
	return 0;
}
