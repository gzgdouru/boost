#include <iostream>
#include <vector>
#include <string>
#include "boost/pool/singleton_pool.hpp"
using namespace std;

class pool_tag {};
typedef boost::singleton_pool<pool_tag, sizeof(int)> spl;

int main(int argc, char *argv[])
{
	int *p = (int*)spl::malloc();
	cout << spl::is_from(p) << endl;

	spl::release_memory();

	getchar();

	return 0;
}