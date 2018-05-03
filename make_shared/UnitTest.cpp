#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr/shared_ptr.hpp"
#include "boost/smart_ptr/make_shared.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	boost::shared_ptr<string> spStr = boost::make_shared<string>("hello word");
	cout << *spStr << endl;

	vector<boost::shared_ptr<int> > vtspInt(10);
	
	int i = 0;
	for (auto pos = vtspInt.begin(); pos != vtspInt.end(); ++pos)
	{
		*pos = boost::make_shared<int>(++i);
		cout << *(*pos) << ",";
	}

	cout << endl;
	getchar();

	return 0;
}