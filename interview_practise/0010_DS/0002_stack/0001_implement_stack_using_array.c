#include <stdio.h>
#define BUFF_SIZE 5

void push (int *);
void pop  (int *);
void display (int *);

int top = -1;

int main (void)
{
	int arr [BUFF_SIZE];
	push (arr);
	push (arr);
	push (arr);
	pop (arr);
	display(arr);
	push (arr);
	push (arr);
	pop (arr);
	push (arr);
	display(arr);
	push (arr);
	push (arr);
	push (arr);
	push (arr);
	push (arr);
	//pop (arr);
	display(arr);
	return 0;
}

void push (int *arr)
{
	//if (BUFF_SIZE == top)
	if (BUFF_SIZE -1 == top )
	{
		printf ("STACK Array buffer is full\n");
		return;
	}
	else
	{
		static int val = 0;
		//arr[top++] = val + 10; // BUG
		val = val + 10;
		arr[++top] = val;
		printf ("PUSH %d element to stack\n",arr[top]);
	}
}

void pop (int *arr)
{
	if (top == -1)
	{
		printf ("stack is empty\n");
		return;
	}
	else
	{
		printf ("POP %d element from stack\n",arr[top]);
		top--;
	}
}

void display (int *arr)
{
	if (top == -1)
	{
		printf ("STACK Array buffer is Empty\n");
		return;
	}
	else
	{
		printf ("\nDisplay stack elements are\n");
		for (int i=top;i>=0;i--)
		{
			printf ("Stack element %d\n",arr[i]);
		}
		printf ("\n");
	}
}
