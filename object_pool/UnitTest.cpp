#include <iostream>
#include <vector>
#include <string>
#include "boost/pool/object_pool.hpp"
using namespace std;

class demo_class
{
public:
	demo_class(int x, int y, int z) :a(x), b(y), c(z)
	{

	}

public:
	int a;
	int b;
	int c;
};

int main(int argc, char *argv[])
{
	boost::object_pool<demo_class> opl;

	demo_class *p = opl.malloc();
	cout << opl.is_from(p) << endl;
	cout << "a:" << p->a << ",b:" << p->b << ",c:" << p->c << endl;

	p = opl.construct(7, 8, 9);
	cout << "a:" << p->a << ",b:" << p->b << ",c:" << p->c << endl;

	boost::object_pool<string> opls;
	for (int i = 0; i < 10; ++i)
	{
		string *psz = opls.construct("hello object pool");
		cout << i << ":" << *psz << endl;
	}

	getchar();

	return 0;
}