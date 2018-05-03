#include <iostream>
#include "boost/date_time/posix_time/ptime.hpp"
#include "boost/date_time/posix_time/posix_time_duration.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/time_formatters.hpp"
#include "boost/date_time/posix_time/time_parsers.hpp"
#include "boost/date_time/posix_time/conversion.hpp"
using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
	namespace pt = boost::posix_time;
	namespace gr = boost::gregorian;


	boost::posix_time::ptime ptTime1(boost::gregorian::date(1992, 8, 15), boost::posix_time::hours(1));
	string szTime1 = boost::posix_time::to_simple_string(ptTime1);
	cout << szTime1 << endl;

	boost::posix_time::ptime ptTime2 = boost::posix_time::time_from_string("1992-08-15 12:00:00");
	cout << boost::posix_time::to_simple_string(ptTime2) << endl;

	boost::posix_time::ptime ptTime3 = boost::posix_time::second_clock::local_time();
	boost::posix_time::ptime ptTime4 = boost::posix_time::microsec_clock::local_time();
	cout << "second:" << boost::posix_time::to_simple_string(ptTime3) << ", microsec:" << boost::posix_time::to_simple_string(ptTime4) << endl;

	pt::ptime ptTime5 = pt::second_clock::local_time();
	gr::date dData = ptTime5.date();
	pt::time_duration tTime = ptTime5.time_of_day();

	cout << "date:" << dData << ", time:" << pt::to_simple_string(tTime) << endl;

	pt::ptime ptTime6 = pt::from_time_t(time(0));
	cout << pt::to_simple_string(ptTime6) << endl;

	getchar();

	return 0;
}