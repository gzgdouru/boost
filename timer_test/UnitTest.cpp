#include <iostream>
#include "boost/timer.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	boost::timer tTime;
	cout << "max timespan:" << tTime.elapsed_max() / 3600 / 24 << "d" << endl;
	cout << "min timespan:" << tTime.elapsed_min() << "s" << endl;

	// 输出对象从创建到现在的时间
	cout << "now time timespan:" << tTime.elapsed() << "s" << endl;
	rename("F:/Boost/vc14/lib/libboost_wserialization-vc140-sgd-1_64.lib", "F:/Boost/vc14/lib/libboost_wserialization-sgd-1_64.lib");
	return 0;
}