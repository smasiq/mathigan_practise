#include <stdio.h>
#include <stdlib.h>
#define WITH_PASSING_LENGTH_NODE 0
#define TWO_POINTER_CONCEPT 1

typedef struct node {
	int data;
	struct node *next;
}node;

void create_node (node **, node **,int *);
#if WITH_PASSING_LENGTH_NODE 
node * find_nth_node_from_end (node *,int,int);
#else
node * find_nth_node_from_end (node *,int);
#endif
void display (node *);

int main (void)
{
	node *head = NULL,*tail = NULL;
	node *ret = NULL;
	int node_pos = 0,count = 0;

	for (int i=0;i<8;i++)
	{
		create_node (&head, &tail,&count);
	}
	display (head);

	printf ("Enter nth node from last\n");
	scanf ("%d",&node_pos);

#if WITH_PASSING_LENGTH_NODE 
	ret = find_nth_node_from_end (head,node_pos,count);
#else
	ret = find_nth_node_from_end (head,node_pos);
#endif

	if (ret == NULL)
	{
		printf ("Node not found\n");
	}
	else
	{
		printf ("%dth node data is %d\n",node_pos,ret->data);
	}

	return 0;
}

void create_node (node ** head, node **tail,int *count)
{
	node *newnode = NULL;
	static int val = 0, sll_count = 1;

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
	*count = sll_count++;
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
		int count = 1;
		while (sll != NULL)
		{
			printf ("data %d: %d\n",count++,sll->data);
			sll = sll->next;
		}
	}
}

#if WITH_PASSING_LENGTH_NODE
node * find_nth_node_from_end (node *head, int node_pos,int sll_count)
{
	if (head == NULL )
	{
		printf ("Given linked list is empty\n");
		return NULL;
	}
	else
	{
		int pos = sll_count - node_pos;
		int i = 1;

		while (i <= pos)
		{
			head = head->next;
			i++;
		}
		return head;
	}
}
#endif

#if TWO_POINTER_CONCEPT
node * find_nth_node_from_end (node *head, int node_pos)
{
	node *fast_ptr = head, *slow_ptr = head;
	int i = 0;

	if (head == NULL )
	{
		printf ("Given linked list is empty\n");
		return NULL;
	}
	else
	{
		while (i < node_pos)
		{
			fast_ptr = fast_ptr->next;
			i++;
		}

		while (fast_ptr != NULL)
		{
			fast_ptr = fast_ptr->next;
			slow_ptr = slow_ptr->next;
		}
		return slow_ptr;
	}
}
#endif
