#include "stdafx.h"
#include <iostream>
#include <boost/timer/timer.hpp>
using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
	boost::timer tTime;
	cout << "max timespan:" << tTime.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan:" << tTime.elapsed_min() << "s" << endl;

	// 输出对象从创建到现在的时间
	cout << "now time timespan:" << tTime.elapasd << "s" << endl;

	return 0;
}