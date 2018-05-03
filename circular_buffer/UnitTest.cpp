#include "../public/headfile.hpp"
#include "boost/circular_buffer.hpp"
#include "boost/assign.hpp"
using namespace boost;

void testOne()
{
	circular_buffer<int> cbInt(5);
	cbInt.push_back(1);
	cbInt.push_front(2);

	cbInt.insert(cbInt.begin(), 3);
	printSTL(cbInt);

	//cbInt.pop_front();
	cbInt.pop_back();
	cout << cbInt[0] << endl;
}

void testTwo()
{
	circular_buffer<int> cbInt(3);
	cbInt.push_back(1);
	cbInt.push_back(2);
	cbInt.push_back(3);
	printSTL(cbInt);

	cbInt.push_back(4);
	printSTL(cbInt);

	cbInt.push_front(5);
	printSTL(cbInt);

	cbInt.pop_front();
	printSTL(cbInt);
}

void testThree()
{
	using namespace boost::assign;
	circular_buffer<int> cbInt(5);
	for (int i = 1; i < 6; ++i)
	{
		cbInt.push_back(i);
	}

	cout << cbInt.full() << endl;

	int *p = cbInt.linearize();
	cout << p[0] << " " << p[3] << endl;

	cbInt.rotate(cbInt.begin() + 2);
	printSTL(cbInt);
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	testThree();

	getchar();
	return 0;
}