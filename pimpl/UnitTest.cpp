#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr/shared_ptr.hpp"
using namespace std;

class sample
{
public:
	sample();
	~sample() {};
	void print();

private:
	class impl;
	boost::shared_ptr<impl> p;
};

class sample::impl
{
public:
	void print()
	{
		cout << "impl print" << endl;
	}
};

sample::sample() :p(new impl)
{

}

void sample::print()
{
	p->print();
}


int main(int argc, char *argv[])
{
	sample testSample;
	testSample.print();

	getchar();

	return 0;
}