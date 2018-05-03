#include "../public/headfile.hpp"
#include "boost/format.hpp"
using namespace std;
using namespace boost;

void testOne()
{
	cout << format("%s:%d + %d = %d\n") % "sum" % 1 % 2 % (1 + 2);

	format fmt("(%1% + %2%) * %3% = %4%\n");
	fmt % 2;
	fmt % 5;
	fmt % ((2 + 5) * 5);
	cout << fmt << endl;
}

int main(int argc, char *argv[])
{
	testOne();

	getchar();

	return 0;
}