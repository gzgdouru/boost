#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr.hpp"
using namespace std;

class self_shared:public boost::enable_shared_from_this<self_shared>
{
public:
	self_shared(int n) :x(n)
	{

	}

	void print()
	{
		cout << "self_shared:" << x << endl;
	}

	int x;
};

int main(int argc, char *argv[])
{
	boost::shared_ptr<self_shared> sp = boost::make_shared<self_shared>(314);
	sp->print();

	boost::shared_ptr<self_shared> p = sp->shared_from_this();
	p->x = 1000;

	p->print();
	sp->print();

	boost::shared_ptr<self_shared> sp2 = sp;
	sp2->x = 2000;
	sp2->print();
	sp->print();
	p->print();

	getchar();

	return 0;
}