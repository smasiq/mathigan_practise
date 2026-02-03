#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

void create_node (node **, node **);
void print_sll (node *);
void reverse_sll (node **);

void create_node (node ** head, node **tail)
{
	node *new_node = NULL;
	static int val = 0;

	new_node = (node *) malloc (sizeof(node));
	if (new_node == NULL)
	{
		printf ("%d:%s malloc failed\n",__LINE__,__func__);
		exit(EXIT_FAILURE);
	}
	val = val + 10;
	new_node->data =  val;
	new_node->next = NULL;

	if (*head == NULL) 
	{
		*head = new_node;
	}
	else
	{
		(*tail)->next = new_node;
	}
		*tail = new_node;
}

void print_sll (node *head)
{
	if (head == NULL)
	{
		printf ("Given linked list is empty\n");
		return;
	}
	else
	{
		for (node *trav = head;trav != NULL; trav = trav->next)
		{
			printf ("data : %d\n",trav->data);
		}
	}
}

void reverse_sll (node **head)
{
	node *curr = *head;
	node *prev = NULL;
	node *beside_node = NULL;

	while (curr != NULL)
	{
		beside_node = curr->next;
		curr->next = prev;
		prev = curr;
		curr = beside_node;
	}
	*head = prev;
}

int main (void)
{
	node *head = NULL, *tail = NULL;
	for (int cnt_node = 1; cnt_node <= 5; cnt_node++)
	{
		create_node (&head,&tail);
	}
	printf ("Before reverse linked list\n");
	print_sll (head);
	reverse_sll (&head);
	printf ("After reverse linked list\n");
	print_sll (head);
	return 0;
}

