#include <iostream>
#include <string>
#include "boost/smart_ptr/scoped_array.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	int *pArray = new int[10];
	boost::scoped_array<int>psaArray(pArray);

	fill_n(&psaArray[0], 10, 6);
	psaArray[5] += 10;

	for (int i = 0; i < 10; ++i)
	{
		cout << psaArray[i] << endl;
	}

	getchar();

	return 0;
}