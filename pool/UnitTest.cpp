#include <iostream>
#include <vector>
#include <string>
#include "boost/pool/pool.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	boost::pool<> pl(sizeof(int));

	int *pInt = (int*)pl.malloc();
	cout << pl.is_from(pInt) << endl;

	pl.free(pInt);

	for (int i = 0; i < 100; ++i)
	{
		pl.ordered_malloc(10);
	}

	int *p = (int*)pl.malloc();
	if (p != NULL)
	{
		*p = 300;
		cout << *p << endl;
	}
	
	getchar();

	return 0;
}