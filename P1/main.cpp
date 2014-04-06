#include <iostream>
#include <climits>
#include "doalg.h"
class testrun
{	int datasize;
	int ksize;
	int numruns;
	int min = INT_MAX;
	int max = 0;
	int avg = 0;
	
public:
	testrun(int d, int k, int n) : 
		datasize(d), 
		ksize(k),
		numruns(n)
	{ }
	const testrun* run()
	{	for(int i = numruns; i > 0; --i)
		{	int res = doalg(datasize, ksize);
			this->min = std::min(this->min, res);
			this->max = std::max(this->max, res);
			avg += res;
		}
		avg /= numruns;
		return this;
	}
	friend std::ostream& operator<< (std::ostream& stream, const testrun& t)
	{	stream << "Testrun: (" << t.datasize << "," << t.ksize << ") " << t.numruns << " runs.  Avg: " << t.avg << " Min: " << t.min << " Max: " << t.max;
		return stream;
}	};

int main (int argc, char** argv)
{	testrun t[] = {
        //	{15, 3, 1000}, 
                //	{100, 10, 1000},
                //	{1000, 20, 1000},
		{10, 3, 1} };
	int numtests = 1;
	for(int i = 0; i < numtests; ++i) std::cout << *(t[i].run()) << std::endl;
	return 0;
}
