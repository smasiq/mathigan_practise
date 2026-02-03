#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
	int data;
	struct list *next;
}list;


list * create_node_sll ( list **, list **);
void display_nodes (list  *);

list * create_node_sll (list ** head, list **tail)
{
	static unsigned int value = 0;
	list * new_node = (list *) malloc (sizeof(list));
	if (new_node == NULL)
	{
		printf ("%d:%s malloc failed\n",__LINE__,__func__);
		exit(EXIT_FAILURE);
	}
	value = value + 10;
	new_node->data = value;
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}

}

void display_nodes (list *head)
{
	int count = 1;
	for (list *traverse = head; traverse != NULL; traverse = traverse->next)
	{
		printf (" node %d : data : %d\n",count++,traverse->data);
	}
}
int main (void)
{
	list *head = NULL, *tail=NULL;
    unsigned int node_count = 0;

	printf ("Enter n nodes\n");
	scanf ("%d",&node_count);

	for (int i=0;i<node_count;i++) 
	{
		create_node_sll (&head,&tail);
	}

    display_nodes (head);
}
