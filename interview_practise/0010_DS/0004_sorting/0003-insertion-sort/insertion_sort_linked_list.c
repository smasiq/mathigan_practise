#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void print_data (node *);
void insert_data (node **, node **);
void insertion_sort (node **);

void insertion_sort (node **head)
{
	node * sorted = NULL;
	node *current = *head;

	if (*head == NULL)
	{
		printf ("%d:%s Receiving Linked list is empty\n",__LINE__,__func__);
		return; 
	}
	while (current)
	{
		node *next = current->next;
		if (!sorted || current->data < sorted->data)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			node *temp = sorted;
			while (temp->next && temp->next->data < current->data)
			{
				temp = temp->next;
			}
			current->next = temp->next;
			temp->next = current;
		}
		current = next;
	}
	*head = sorted;
}

void print_data (node *head)
{
	if (head == NULL)
	{
		printf ("%d:%s Receiving Linked list is empty\n",__LINE__,__func__);
		return; 
	}
	for (node *trav = head; trav != NULL; trav = trav->next)
	{
		printf ("%d\n",trav->data);
	}
}

void insert_data (node **head, node **tail)
{
	node * new_node = (node*) malloc (sizeof(node));
	if (new_node == NULL)
	{
		printf ("%d:%s new_node is NULL\n",__LINE__,__func__);
		exit(EXIT_FAILURE);
	}
	printf ("Enter Data\n");
	scanf ("%d",&new_node->data);
	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = (*tail)->next;
	}

}

int main (void)
{
	node *head = NULL, *tail = NULL;
	
	for (int i=1;i<=5;i++)
	{
		insert_data (&head,&tail);
	}
	printf ("Before insertion sorting ...\n");
	print_data (head);
	insertion_sort (&head);
	printf ("After insertion sorting ...\n");
	print_data (head);
	return 0;
}
