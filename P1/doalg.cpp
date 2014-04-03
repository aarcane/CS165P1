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
	sort(k, Best);
	//Cleanup and returns.

	ret = COMPARE(-1, k, Best); //better return a positive value.
	delete[] Best;
	return ret;
}

// Heapify argv from indeces 1 to argc.
void heapify (const int argc, int * argv)
{

}

// Iterate through hidden array in COMPARE from k+1 to n and find k largest values.
void findLargest (const int n, const int k, int * argv)
{

}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{

}
