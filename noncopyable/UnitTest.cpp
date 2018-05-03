#include <iostream>
#include <vector>
#include <string>
#include "boost/utility.hpp"
using namespace std;

class do_not_copy :boost::noncopyable
{
public:
	do_not_copy() {}
	~do_not_copy() {}
};

int main(int argc, char *argv[])
{
	do_not_copy d1;
//	do_not_copy d2(d1);
	do_not_copy d3 = d1;

	return 0;
}