#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

void print_data (node *);
void insert_data (node **, node **);
void bubble_sort (node **);

void bubble_sort (node **head)
{
	int is_sorted = 0;

	if (*head == NULL)
	{
		printf ("%d:%s Receiving Linked list is empty\n",__LINE__,__func__);
		return; 
	}
    
	for (node *f_trav = *head; f_trav != NULL; f_trav=f_trav->next)
	{
		//for (node *s_trav = *head; s_trav != NULL; s_trav=s_trav->next) 
		//above line cause crash due to traverse till null
		//when I check n+1 < n (n+1 like Null->data it leads to crash)
		for (node *s_trav = *head; s_trav->next != NULL; s_trav=s_trav->next)
		{
			if (s_trav->data > s_trav->next->data)
			{
				is_sorted = 1;
				int temp = s_trav->data;
				s_trav->data = s_trav->next->data;
				s_trav->next->data = temp;
			}
		}
		if (is_sorted == 0)
			break;
		else
			is_sorted = 1;
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
	
	for (int i=1;i<=5;i++)
	{
		insert_data (&head,&tail);
	}
	printf ("Before bubble sorting ...\n");
	print_data (head);
	bubble_sort (&head);
	printf ("After bubble sorting ...\n");
	print_data (head);
	return 0;
}
