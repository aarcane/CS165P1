#include "COMPARE.h"
int doalg(int n, int k)
{	int * Best;
	Best = new int [k];
	COMPARE(0,n); //allocate hidden array
	return COMPARE(-1, k, Best);	
	//return 0;
}
