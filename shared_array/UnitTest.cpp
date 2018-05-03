#include <iostream>
#include <vector>
#include <string>
#include "boost/smart_ptr.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	int *pInt = new int[100];
	boost::shared_array<int> p(pInt);
	boost::shared_array<int> p2 = p;
	p[0] = 100;

	cout << p2[0] << endl;

	getchar();

	return 0;
}