#include "../public/headfile.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/assert.hpp"
#include "boost/format.hpp"
using namespace boost;

#define BOOST_ENABLE_ASSERT_HANDLER

namespace boost
{
	void assertion_failed(char const * expr, char const * function, char const * file, long line)
	{
		format fmt("Assertion failed!\n Expression: %s\n Function: %s\n File: %s\n Line: %d\n");
		fmt %expr %function %file %line;
		cout << fmt.str() << endl;
	}
}

int func(int x)
{
	BOOST_ASSERT(x != 0 && "divided by zero");
	return 1 / x;
}

void testOne()
{
	func(0);
}

int main(int argc, char *argv[])
{
	testOne();

	getchar();
	return 0;
}