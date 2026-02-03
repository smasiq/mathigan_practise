#include <stdio.h>
#include <stdlib.h>
#define BRUTE_FORCE_METHOD 0
#define HASH_METHOD 1

typedef struct node {
	int data;
	struct node *next;
}node;

void create_node (node **, node **);
void remove_duplicate_node (node *);
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

	remove_duplicate_node (head);
	printf ("After remove duplicate node\n");
	display (head);
	return 0;
}

void create_node (node ** head, node **tail)
{
	node *newnode = NULL;
	static int node_count = 1;
	int val = 0;

	newnode = (node *) malloc (sizeof(node));
	if (newnode == NULL)
	{
		printf ("%d:%s func malloc failed\n",__LINE__,__func__);
		exit(EXIT_FAILURE);
	}
	
	printf ("Enter data for node %d\n",node_count++);
	scanf  ("%d",&val);

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

#if HASH_METHOD 
void remove_duplicate_node(node *head)
{
    int seen[1000] = {0};  // <-- acts like a hash table (simplified)
    node *current = head;
    node *prev = NULL;

    while (current != NULL) {
        if (seen[current->data]) {
            // Duplicate found — delete it
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            seen[current->data] = 1;
            prev = current;
            current = current->next;
        }
    }
}
#endif

#if BRUTE_FORCE_METHOD
void remove_duplicate_node (node *head)
{
	node *temp = head; 
	//node *prev = NULL;
	node *prev = head;

	//for (; temp != NULL;temp=temp->next)
	while (temp != NULL)
	{
		node *temp1 = temp->next;
		prev = temp1;
		//for (node *temp1 = temp->next; temp1 != NULL; temp1=temp1->next)
		while (temp1 != NULL)
		{
			if (temp->data == temp1->data)
			{
				node *del = temp1;
				prev->next = del->next;
				temp1 = temp1->next;
				free(del);
			}
			else 
			{
				prev = temp1;
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
	}
}
#endif

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
