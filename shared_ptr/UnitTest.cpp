#include <iostream>
#include <string>
#include "boost/smart_ptr/shared_ptr.hpp"
using namespace std;

class CShared
{
public:
	CShared(boost::shared_ptr<int> spInt) : m_spInt(spInt)
	{

	}

	~CShared()
	{

	}

	void print()
	{
		cout << "count:" << m_spInt.use_count() << ",value:" << *m_spInt << endl;
	}

	void print_func(boost::shared_ptr<int> spInt)
	{
		cout << "count:" << spInt.use_count() << ",value:" << *spInt << endl;
	}

private:
	boost::shared_ptr<int> m_spInt;
};

int main(int argc, char *argv[])
{
	boost::shared_ptr<int> spInt(new int(100));
	CShared Shared1(spInt);
	CShared Shared2(spInt);

	Shared1.print();
	Shared2.print();

	*spInt = 20;
	Shared2.print_func(spInt);

	Shared1.print();

	getchar();

	return 0;
}