/*
 *  Determine the intersection of two integer arrays.

    WTD: Compare every element of the two arrays, listing down the common integers that appear in both.

    (e.g.: I/P: [1,2,4,5,6], [2,3,5,7], O/P: [2,5])
 *
 * */

#include <stdio.h>

int * intersect_of_two_arr (const int * , const int , const int *, const int ,int *);

int * intersect_of_two_arr (const int * arr_1, const int size_1, const  int *arr_2, const int size_2,int *eoe)
{
//	int size = (size_1 > size_2) ? size_1 : size_2;
//	static int ret[size];
	static int ret[10];
	int k=0, is_already_present = 0;

	for (int i=0; i< size_1; i++)
	{
		for (int j=0; j<size_2; j++)
		{
			//if (is_already_present == 1)
			//{
			//	break;
			//}

			//for (int i=0;i<k;i++)  
			/*
			 * DON'T USE i VARIABLE IF ALREADY USED IN SAME FUNCTION
			 * IT WILL SHADOWED VARIABLE AUTOMATICALLY BY COMPILER
			 * (COMPILER WON'T INFORM UNTIL ENABLE -Wshadow FLAG
			 * IT WILL CHANGE OUTER LOOP i VARIABLE VALUE AFTER
			 * MODIFY INNER i VARIABLE.		
			 * */
			for (int m=0;m<k;m++)
			{
				if (ret[m] == arr_1[i] )
				{
					is_already_present = 1;
					break;
				}
			}
			if (is_already_present == 0)
			{
				if (arr_1[i] == arr_2[j])
				{
					*(ret+k) = arr_2[j];
					is_already_present = 1;
					k++;
				}
			}
		}
		is_already_present = 0;
	}
	if (k>0)
	{
		*eoe = k;
		return ret;
	}
	else
		return NULL;
}

int main (void)
{
	int arr_1[] = {1,2,4,5,5,5,5,5,6} , arr_2[] = {2,2,2,2,3,5,5,7};
	int size_1 = sizeof(arr_1) / sizeof(arr_1[0]);
	int size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    int *ret = NULL, eoe=0;

	ret = intersect_of_two_arr (arr_1, size_1,arr_2,size_2,&eoe);

	// how to know length of return type when return from function
	for (int i=0; i<eoe;i++)
		printf ("intersection element from arr is %d\n",ret[i]);

	return 0;
}
