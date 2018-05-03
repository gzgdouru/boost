#include "../public/headfile.hpp"
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"
#include "boost/tuple/tuple_io.hpp"
#include "boost/assign.hpp"

void testOne()
{
	boost::tuple<int, string, double> tp = boost::make_tuple(1, "szStr", 100.0);
	cout << tp.get<0>() << endl;
	cout << tp.get<2>() << endl;

	cout << ++tp.get<0>() << endl;
}

void testTwo()
{
	boost::tuple<int, string, double> tp = boost::make_tuple(1, "szStr", 100.0);
	boost::tuple<int, string, double> tp2 = boost::make_tuple(1, "szStr", 100.0);

	cout << (tp == tp2) << endl;
}

void testThree()
{
	boost::tuple<int, double, string> tp = boost::make_tuple(1, 100.0, "szStr");
	cout << tp << endl;

	cin >> tp;
	cout << tp;
	cout << boost::tuples::set_open('[') << boost::tuples::set_close(']');
	cout << boost::tuples::set_delimiter(',');
	cout << tp << endl;

}

boost::tuple<int, double, string> func()
{
	return boost::make_tuple(1, 199.00, "hello");
}

void testFour()
{
	int i;
	double d;
	string s;
	boost::tie(i, d, s) = func();
	cout << i << " " << d << " " << s << endl;

	d = 0.0;
	boost::tie(boost::tuples::ignore, d, boost::tuples::ignore) = func();
	cout << d << endl;
}

void testFive()
{
	using namespace boost::assign;
	typedef boost::tuple<int, double, string> my_tuple;

	//my_tuple tp = boost::make_tuple(1, 1.0, "hello");

	vector<my_tuple> vtTp = boost::assign::tuple_list_of(1, 1.0, "hello") (2, 2.0, "hello hi");
	cout << vtTp.size() << endl;

	vtTp += boost::make_tuple(3, 3.0, "hello");
	vtTp += boost::make_tuple(4, 4.0, "hello");
	cout << vtTp.size() << endl;
}

void testSix()
{
	boost::tuple<int, double, string> tp = boost::make_tuple(1, 1.0, "hello");
	printTuple(tp);
}

int main(int argc, char* argv[])
{
	//testOne();

	//testTwo();

	//testThree();

	//testFour();

	/*testFive();*/

	testSix();

	getchar();

	return 0;
}