#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include "doalg.h"

class testrun
{	int datasize;
	int ksize;
	int numruns;
	int min = INT_MAX;
	int max = 0;
	double avg = 0.0f;
	
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
{	testrun defaulttests[] = { // per the assignment
		{15, 3, 1000}, 
		{100, 10, 1000},
		{1000, 20, 1000},
		{10000, 40, 1000} };
	int defaultnumtests = 4; // per the assignment
	std::string usage = ": read README.txt"; // should expand on this...
	std::vector<testrun> t; // Store test runs
	static const int precision = 3; // per the assignment
	
	if(argc == 1) // No arguments passed.  run default test pattern.
	{	for(int i = 0; i < defaultnumtests; ++i) t.push_back(defaulttests[i]);
	}
	else if(argc % 3 == 1) 	for( int i = 1; i < argc; i+=3) // run specified tests, or die trying!
	{	int n, k, r = 3; // 1 doesn't work well.  things crash on anything less than 3.
		try
		{	n = std::stoi(argv[i]);
			k = std::stoi(argv[i+1]);
			r = std::stoi(argv[i+2]);
		}
		catch(std::exception e) 
		{	std::cerr << "Exception: " << e.what() << std::endl; // should maybe error out here, but better to try to continue methinks.
		}
		t.emplace_back(n, k, r);
	}
	else
	{	std::cerr << argv[0] << usage << std::endl;
		return -1; // someone didn't read the manual u,.,u
	}
	std::cout << std::fixed << std::setprecision(precision); // per the assignment
	for(std::vector<testrun>::iterator i = t.begin(); i != t.end(); ++i) std::cout << *(i->run()) << std::endl;
	return 0;
}
