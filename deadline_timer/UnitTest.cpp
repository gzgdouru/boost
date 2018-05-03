#include "../public/headfile.hpp"
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
using namespace boost::asio;

void testOne()
{
	io_service ios;
	deadline_timer t(ios, posix_time::seconds(5));

	cout << t.expires_at() << endl;
	cout << t.expires_from_now() << endl;

	t.wait();
	cout << "hello asio" << endl;
}

void print(const boost::system::
	_code &e)
{
	cout << "hello asio" << endl;
}

void testTwo()
{
	io_service ios;
	deadline_timer t(ios, posix_time::seconds(5));

	t.async_wait(print);

	cout << "it show before t expired." << endl;
	ios.run();
}

class a_timer
{
public:
	template<typename F>
	a_timer(io_service &ios, int x, F func) :
		f(func), count_max(x), count(0),
		t(ios, posix_time::seconds(5))
	{
		t.async_wait(bind(&a_timer::call_func, this, boost::placeholders::_1));
	}

	void call_func(const boost::system::error_code &e)
	{
		if (count >= count_max)
		{
			return;
		}

		++count;

		f();
		t.expires_at(t.expires_at() + posix_time::milliseconds(500));
		t.async_wait(bind(&a_timer::call_func, this, _1));
	}

private:
	int count;
	int count_max;
	boost::function<void()> f;
	deadline_timer t;
};

void print1()
{
	cout << "hello asio" << endl;
}

void print2()
{
	cout << "hello boost" << endl;
}

void testThree()
{
	io_service ios;
	a_timer at1(ios, 5, print1);
	a_timer at2(ios, 5, print2);

	ios.run();
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	testThree();

	getchar();
	return 0;
}