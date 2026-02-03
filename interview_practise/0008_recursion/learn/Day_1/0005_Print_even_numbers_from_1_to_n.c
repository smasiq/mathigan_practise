#include <stdio.h>

void print_even_nos (int ,int);

void print_even_nos (int start_val, int n)
{
	int arr[99000];
	if (start_val == n)
		return ;
	if ( start_val % 2 == 0)
		printf ("%d ",start_val);

	//print_even_nos (start_val++, n);
	print_even_nos (start_val +1, n);
	//print_even_nos (start_val++, n);
	//
	// above is bug bcz it post increment it pass old value 
	// only. So every call it pass old value it recursively call till
	// get seg fault.
	
	//print_even_nos (++start_val, n);
	/*
	 * Case 1: print_even_nos(start_val + 1, n);
	 * ✅ Best and safest.
	 * It increases the value only for the recursive call without changing the current start_val.
	 * Case 2: print_even_nos(++start_val, n);
	 * ⚠️ Not recommended (though it will work, the logic gets confusing).
	 * Here’s why:
	 * ++start_val modifies start_val in the current frame before the recursive call.
	 * That means after the recursive call returns, your local start_val in the current function is already changed.
	 * So you lose the original start_val value — which can be problematic if later you need it (e.g., for tail recursion, debugging, etc.).
	 *
	 * */
}

int main (void)
{
	int n = 10, start_val = 1;
	print_even_nos (start_val, n);
	return 0;
}
