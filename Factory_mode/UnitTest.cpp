#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr/shared_ptr.hpp"
using namespace std;

class abstract
{
public:
	virtual void f() = 0;
	virtual void g() = 0;

protected:
	virtual ~abstract() {}
};

class impl :public abstract
{
public:
	virtual void f()
	{
		cout << "class impl f()" << endl;
	}

	virtual void g()
	{
		cout << "class impl g()" << endl;
	}
};

boost::shared_ptr<abstract> create()
{
	return boost::shared_ptr<abstract>(new impl);
}

int main(int argc, char *argv[])
{
	boost::shared_ptr<abstract> p = create();
	p->f();
	p->g();

	getchar();

	return 0;
}