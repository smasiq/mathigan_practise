#include <stdio.h>
#include <stdlib.h>

int g_var;
static int int_g_var = 200;

int main (void)
{
	int l_var, int_lvar = 100;
	static int var, int_var = 300;

	int *lmalloc = (int *) malloc (sizeof(int));
	if (lmalloc == NULL)
	{
		printf ("%s:%d malloc failed\n",__func__,__LINE__);
		exit(EXIT_FAILURE);
	}

    *lmalloc = 400;

	printf ("local variables l_var = %d addr of l_var = %p\n"
	        "local intialize variables int_lvar = %d, addr of int_lvar = %p\n"
			"local static variables var = %d, addr of var = %p\n"
			"local static intialize variables int_var = %d, addr of int_var = %p\n"
			"local malloc variable *lmalloc = %d addr of lmalloc = %p\n",
			 l_var, &l_var, int_lvar, &int_lvar, var, &var, int_var, &int_var,
			 *lmalloc, lmalloc);

	printf ("global variable g_var = %d addr of g_var = %p\n"
		    "global intialize variable int_g_var = %d addr of int_g_var = %p\n",
			 g_var, &g_var, int_g_var, &int_g_var);

	return 0;
}
