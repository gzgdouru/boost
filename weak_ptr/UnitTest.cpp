#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	boost::shared_ptr<int> spInt(new int(10));
	cout << "shared_ptr use_count:" << spInt.use_count() << endl;

	boost::weak_ptr<int> wpInt(spInt);
	cout << "weak_ptr use_count:" << wpInt.use_count() << endl;

	if (!wpInt.expired())
	{
		boost::shared_ptr<int> spInt2 = wpInt.lock();
		*spInt2 = 100;
		cout << "weak_ptr use_count:" << wpInt.use_count() << endl;
	}

	cout << "weak_ptr use_count:" << wpInt.use_count() << endl;
	cout << *spInt << endl;

	spInt.reset();
	cout << wpInt.expired() << endl;
	if (!wpInt.lock())
	{
		cout << "wear_ptr is null" << endl;
	}

	getchar();

	return 0;
}