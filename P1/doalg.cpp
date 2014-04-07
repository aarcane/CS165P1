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

	int * Rest = new int[n-k+1]; // stores indices of k - n
        int indexOffset = k+1; 
        
         std::cout << "REST CONTAINS: " << std::endl; 
        for(int i= 1; i<=n-k; i++)
          {
            std::cout << indexOffset << std::endl;
            Rest[i] = indexOffset; //initialize Rest to array[n-k+1] to array[n]
            indexOffset ++; 
          }
        std::cout << "---------------: " << std::endl; 
        
        
	COMPARE(0,n); //allocate hidden array
	
	// Meat of stuff goes here.
	heapify(k, Best);
	findLargest(n, k, Best, Rest);
	Sort(k, Best);
	//Cleanup and returns.

	ret = 1; //COMPARE(-1, k, Best); //better return a positive value.
	delete[] Best;
        delete[] Rest; 
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
    else if (compareRet == 2) // r > l
    {
      return false; 
    } 
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
    minHeap.push(i);
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
void findLargest (const int n, const int k, int * argv, int * Rest)
{ 
  //For each element, after the kth element (arr[k] to arr[n-1]), compare it with root of MH.
  //……a) If the element is greater than the root then make it root and call heapify for MH
  //……b) Else ignore it.

  //Compare root of MH to Best[] to find largest
  
   int compareRet = 0; 
   for(int i = 1; i <= n-k; i ++)
    {
      compareRet = COMPARE(Rest[i], minHeap.top());
      
      if(compareRet == -1)//x and y are not in range
      {
        std::cout << "x or y out of range" << std::endl;
      }
      else if(compareRet == 1) // element is greater, make it root
      {
        minHeap.pop();
        minHeap.push(Rest[i]);
      }
    }

   for(int i = 1; i <= k; i ++)
   {
     argv[i] = minHeap.top();
     minHeap.pop();
   }
   std::cout << "CHECK BEST" << std::endl; 
   std::cout << COMPARE(-1, k, argv) << std::endl; 
   
  
}

// Perform an in place sort of the items in the given array from position 1 to position k
void Sort (const int k, int * argv)
{

}
