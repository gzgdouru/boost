#include <iostream>
#include <string>
#include "boost/smart_ptr/scoped_ptr.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	boost::scoped_ptr<string> p_spStr(new string("scoped_ptr test"));
	cout << "string size:" << p_spStr->size() << ",content:" << *p_spStr << endl;

	boost::scoped_ptr<int> spInt(new int);
	*spInt = 100;
	cout << *spInt << endl;

	// ÖÃ¿Õscoped_ptrÖ¸Õë
	spInt.reset();

	if (!spInt)
	{
		cout << "spInt is null" << endl;
	}

	getchar();

	return 0;
}