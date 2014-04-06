#include "COMPARE.h"
#include "doalg.h"
#include <queue>
#include <vector>
#include <functional>
#include <iostream>



int doalg(const int n, const int k)
{	
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
// Struct for overloading default comparator in priority_queue
struct compare  
{  
  bool operator()(const int& l, const int& r)  
  {  
    int compareRet = COMPARE(l, r); 
    if (compareRet == -1)
    {
      std::cout << "x or y out of range" << std::endl;
    } 
    return Best[l] > Best[r];
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

  
  while(!minHeap.empty())
    {
      std::cout << Best[minHeap.top()] << std::endl;
      minHeap.pop();
    }

}

// Iterate through hidden array in COMPARE from k+1 to n and find k largest values.
void findLargest (const int n, const int k, int * argv)
{	std::swap(argv[1], argv[2]);

}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{

}
