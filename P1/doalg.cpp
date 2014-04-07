#include "COMPARE.h"
#include "doalg.h"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>


int doalg(const int n, const int k)
{	
	int ret = 0;
	int * Best = new int [k+1]; // stores indices of first k
        
        std::cout << "BEST CONTAINS: " << std::endl; 
	for(int i=1; i<=k;++i) 
          {
            std::cout << i << std::endl; 
            Best[i] = i; //initialize Best to first N values.
          }
         std::cout << "---------------: " << std::endl; 
        
        
	COMPARE(0,n); //allocate hidden array
        std::cout << COMPARE(1,2);
        std::cout << COMPARE(1,3);
        std::cout << COMPARE(2,3);
        std::cout << COMPARE(3,3);
        //COMPARE(
        std::cout << "n: " << n << std::endl;	
	// Meat of stuff goes here.
	heapify(k, Best);
	findLargest(n, k, Best);
	Sort(k, Best);
	//Cleanup and returns.

	ret = 1; //COMPARE(-1, k, Best); //better return a positive value.
	delete[] Best;
	return ret;
}
// Struct for overloading default comparator in priority_queue
struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
    int compareRet = COMPARE(l, r); 
    std::cout << "l: " << l << " r: " << r << " c: " << compareRet;
    if (compareRet == -1)
    {
      std::cout << " x or y out of range c: " << compareRet;
    }
    else if (compareRet == 2) // r > l
      {  std::cout << std::endl;
      return false; 
    } 
    std::cout << std::endl;
    return true; // l > r
  }
};

// Create priority queue for use as minHeap
std::priority_queue<int, std::vector<int>, compare > minHeap;

// Heapify argv from indeces 1 to argc.
void heapify (const int argc, int * argv)
{

  // Push elements onto MinHeap
  for(int i = 1; i <= argc; i ++)
  {
    minHeap.push(argv[i]);
  }
  /*
  std::cout << " MINHEAP ELEMENTS " << std::endl; 
   while(!minHeap.empty())
    {
      std::cout << argv[minHeap.top()] << std::endl;
      minHeap.pop();
    }
  */
  
}

// Iterate through hidden array in COMPARE from k+1 to n and find k largest values.
void findLargest (const int n, const int k, int * argv)
{ 
  //For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
  //……a) If the element is greater than the root then make it root and call heapify for MH
  //……b) Else ignore it.

  //Compare root of MH to Best[] to find largest
  
   int compareRet = 0; 
   for(int i = k; i <= n; ++i)
    {
      compareRet = COMPARE(i, minHeap.top());
      
      if(compareRet == -1)//x and y are not in range
      {
        std::cout << "x or y out of range" << std::endl;
      }
      else if(compareRet == 1) // element is greater, make it root
      {
        minHeap.pop();
        minHeap.push(i);
      }
    }

   for(int i = 1; i <= k; ++i)
   {
     argv[k-i+1] = minHeap.top();
     minHeap.pop();
   }
   std::cout << "CHECK BEST" << std::endl; 
   std::cout << COMPARE(-1, k, argv) << std::endl; 
   
  
}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{

}

void percDown(const int k, const int n, int * argv)
{	int cmp = n*2;
	int c = 0;
	if(n > k) return;
	if(cmp > k) return;
	if((cmp+1) <= k)
	{	c = COMPARE(argv[cmp], argv[cmp+1]);
		if(c == -1) {/* index out of bounds.  why? */}
		else if (c == 1) /* y is a better cmp */
		{	cmp += 1;
		}
		else if (c == 2) { /* cmp is already best option */}
		else {/* unspecified error. */}
	}
	c = COMPARE(argv[n], argv[cmp]);
	if(c == -1) {/* index out of bounds.  why? */}
	else if (c == 1) /* swap n and cmp, recurse */
	{	std::swap(argv[n], argv[cmp]);
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

void percDown2(const int k, int n, int* argv)
{	int cmp = n*2;
	while(cmp <= k && n <= k)
	{	if(cmp+1 <= k) cmp=(1==COMPARE(argv[cmp], argv[cmp+1]))?cmp+1:cmp;
		if(1==COMPARE(argv[n], argv[cmp]))
		{	std::swap(argv[n], argv[cmp]);
			n = cmp; // recurse, if applicable.
		}
		else return; // actually done.  Don't recurse.
	}
	return;
}
