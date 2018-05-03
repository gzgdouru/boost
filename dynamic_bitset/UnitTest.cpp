#include "../public/headfile.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/utility/binary.hpp"
using namespace boost;

void testOne()
{
	dynamic_bitset<> dbit(5, BOOST_BINARY(01110));
	cout << dbit << endl;

	dbit.push_back(true);
	cout << dbit << endl;

	dbit.append(BOOST_BINARY(101));
	cout << dbit << endl;
}

void testTwo()
{
	dynamic_bitset<> dbit(4, BOOST_BINARY(1010));
	dbit[0] &= 1;
	dbit[1] ^= 1;
	cout << dbit << endl;

	dynamic_bitset<> dbit2(4, BOOST_BINARY(0101));
	cout << (dbit > dbit2) << endl;

	cout << (dbit ^ dbit2) << endl;
	cout << (dbit | dbit2) << endl;
}

void testThree()
{
	dynamic_bitset<> dbit(8, BOOST_BINARY(10101110));
	cout << dbit.flip() << endl;

	cout << dbit.set() << endl;

	cout << dbit.reset() << endl;

	dbit.set(1);
	cout << dbit << endl;

	cout << dbit.count() << endl;
}

int main(int argc, char *argv[])
{
	//testOne();

	/*testTwo();*/

	testThree();

	getchar();
	return 0;
}