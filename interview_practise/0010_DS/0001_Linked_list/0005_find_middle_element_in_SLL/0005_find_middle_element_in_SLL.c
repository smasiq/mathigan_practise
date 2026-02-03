#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node;

void create_node (node **, node **);
node * find_middle_node (node *);
void display (node *);

int main (void)
{
	node *head = NULL,*tail = NULL;
	node *ret = NULL;

	for (int i=0;i<8;i++)
	{
		create_node (&head, &tail);
	}
	display (head);

	ret = find_middle_node (head);
	if (ret == NULL)
		printf ("No node present in given linked list\n");
	else
		printf ("Middle node data : %d\n",ret->data);

	return 0;
}

void create_node (node ** head, node **tail)
{
	node *newnode = NULL;
	static int val = 0;

	newnode = (node *) malloc (sizeof(node));
	if (newnode == NULL)
	{
		printf ("%d:%s func malloc failed\n",__LINE__,__func__);
		exit(EXIT_FAILURE);
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

node * find_middle_node (node *head)
{
	node *fast = head, *slow = head;

	if (head == NULL)
	{
		printf ("%d:%s func given linked list is empty\n",__LINE__,__func__);
		return NULL;
	}
	else
	{
		//while (fast->next != NULL)
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	return slow;
}

void display (node *sll)
{
	if (sll == NULL)
	{
		printf ("%d:%s func given linked list is empty\n",__LINE__,__func__);
		return ;
	}
	else
	{
		while (sll != NULL)
		{
			printf ("data : %d\n",sll->data);
			sll = sll->next;
		}
	}
}
