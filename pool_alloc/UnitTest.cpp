#include <iostream>
#include <vector>
#include <string>
#include "boost/pool/pool_alloc.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	vector<int, boost::pool_allocator<int> >v;

	v.push_back(10);
	cout << v.size() << endl;

	getchar();

	return 0;
}