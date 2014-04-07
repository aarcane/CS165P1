#include "COMPARE.h"
#include "doalg.h"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>
// Struct for overloading default comparator in priority_queue
struct compare
{
  bool operator()(const int& l, const int& r)
  {
    int compareRet = COMPARE(l, r);
    //std::cout << "l: " << l << " r: " << r << " c: " << compareRet;
    if (compareRet == -1)
    {
      std::cerr << " x or y out of range c: " << compareRet << std::endl;
	return false;
    }
    else if (compareRet == 2) // r > l
      {  //std::cout << std::endl;
      return false;
    }
    //std::cout << std::endl;
    return true; // l > r
  }
};


// Create priority queue for use as minHeap
std::priority_queue<int, std::vector<int>, compare > minHeap;

int doalg(const int n, const int k)
{	
	int ret = 0;
	int * Best = new int [k+1]; // stores indices of first k
        Best[0] = -1;
	for(int i=1; i<=k;++i) Best[i] = i; //initialize Best to first N values.
        
	COMPARE(0,n); //allocate hidden array

	// Meat of stuff goes here.
	heapify(k, Best);
	findLargest(n, k, Best);
	Sort(k, Best);
	//Cleanup and returns.
	
	//std::cerr << "heapify(): ";
	//for(int i = 1; i <=k; ++i) std::cerr << Best[i];
	//std::cerr << std::endl;
	ret = COMPARE(-1, k, Best); //better return a positive value.

	for(int i = 1; i <= k; ++i)
	{	Best[minHeap.size()] = minHeap.top();
		minHeap.pop();
	}
	//std::cerr << "std::priority_queue(): ";
	//for(int i = 1; i <= k; ++i) std::cerr << Best[i];
	//std::cerr << std::endl;
	ret = COMPARE(-1, k, Best);

	delete[] Best;
	return ret;
}

// Heapify argv from indeces 1 to argc.
void heapify (const int argc, int * argv)
{
  // Push elements onto MinHeap
  for(int i = 1; i <= argc; ++i)
  {
    minHeap.push(i);
  }
	for(int i = argc; i > 0; --i) percDown(argc, i, argv);
}

// Iterate through hidden array in COMPARE from k+1 to n and find k largest values.
void findLargest (const int n, const int k, int * argv)
{ 
  //For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
  //……a) If the element is greater than the root then make it root and call heapify for MH
  //……b) Else ignore it.

  //Compare root of MH to Best[] to find largest
  
   int compareRet = 0; 
   for(int i = k+1; i <= n; ++i)
    {
      compareRet = COMPARE(i, minHeap.top());
      
      if(compareRet == -1)//x and y are not in range
      {
        std::cerr << "x or y out of range" << std::endl;
      }
      else if(compareRet == 1) // element is greater, make it root
      {
        minHeap.pop();
        minHeap.push(i);
      }

      compareRet = COMPARE(i, argv[1]);
      if(compareRet == -1) std::cerr << "x or y are out of range" << std::endl;
      else if(compareRet == 1)  //perc Down
      {	argv[1] = i;
	percDown(k, 1, argv);
      }
    }
}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{	for(int i = k; i >= 1; --i)
	{	std::swap(argv[1], argv[i]);
		percDown(i-1, 1, argv);
	}
}

void percDown(const int k, int n, int* argv)
{	int cmp = n*2;
	while(cmp<=k && n<=k)
	{	cmp=((1+cmp)<=k && 1==COMPARE(argv[cmp], argv[(1+cmp)]))?(1+cmp):cmp;
		if(1==COMPARE(argv[n], argv[cmp]))
		{	std::swap(argv[n], argv[cmp]);
			n = cmp; // recurse, if applicable.
			cmp *= 2;
		}
		else return; // actually done.  Don't recurse.
	}
	return;
}
