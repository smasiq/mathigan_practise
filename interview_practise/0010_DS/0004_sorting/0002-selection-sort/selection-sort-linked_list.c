#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void print_data (node *);
void insert_data (node **, node **);
void selection_sort (node **);

void selection_sort (node **head)
{
	node * ss_node = NULL;

	if (*head == NULL)
	{
		printf ("%d:%s Receiving Linked list is empty\n",__LINE__,__func__);
		return; 
	}
    
	for (node *f_trav = *head; f_trav->next != NULL; f_trav=f_trav->next)
	{
		ss_node = f_trav;
		for (node *s_trav = f_trav->next; s_trav != NULL; s_trav = s_trav->next)
		{
			if (s_trav->data < ss_node->data)
			{
				ss_node = s_trav;
			}
		}
		int temp = ss_node->data;
		ss_node->data = f_trav->data;
		f_trav->data = temp;
	}
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
	
	for (int i=1;i<=10;i++)
	{
		insert_data (&head,&tail);
	}
	printf ("Before selection sorting ...\n");
	print_data (head);
	selection_sort (&head);
	printf ("After selection sorting ...\n");
	print_data (head);
	return 0;
}
