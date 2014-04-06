#include <iostream>
#include "COMPARE.h"
#include "doalg.h"
int doalg(const int n, const int k)
{	int * Best;
	int ret = 0;
	Best = new int [k+1];
	for(int i=0; i<=k;++i) Best[i] = i; //initialize Best to first N values.
	
	COMPARE(0,n); //allocate hidden array
	
	// Meat of stuff goes here.
	heapify(k, Best);
	findLargest(n, k, Best);
	Sort(k, Best);
	//Cleanup and returns.

	ret = 1; //COMPARE(-1, k, Best); //better return a positive value.
	delete[] Best;
	return ret;
}

// Heapify argv from indeces 1 to argc.
void heapify (const int argc, int * argv)
{

}

// Iterate through hidden array in COMPARE from k+1 to n and find k largest values.
void findLargest (const int n, const int k, int * argv)
{	std::swap(argv[1], argv[2]);

}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{

}

void percDown(const int k, const int n, int * argv)
{	if(n >= k) return;
	if((n*2) >= k) return;
	int cmp = n*2;
	int c = 0;
	if(((n*2)+1) <k)
	{	c = COMPARE(argv[2*n], argv[(2*n)+1]);
		if(c == -1) {/* index out of bounds.  why? */}
		else if (c == 1) /* y is a better cmp */
		{	cmp = (n*2)+1;
		}
		else if (c == 2) { /* cmp is already best option */}
		else {/* unspecified error. */}
	}
	c = COMPARE(argv[n], argv[cmp]);
	if(c == -1) {/* index out of bounds.  why? */}
	else if (c == 1) /* swap n and cmp, recurse */
	{	std::swap(n, cmp);
		percDown(k, cmp, argv);
	}
	else if (c == 2) {/* n is already in proper order.*/}
	else {/* unspecified error. */}
	return;

}
/*	COMPARE( x,y ) compares values of array[x] and array[y]	*/
/*		returns  1 if array[x] > array[y]		*/
/*		returns  2 if array[y] > array[x]		*/
/*		returns -1 if x or y is out of range		*/
