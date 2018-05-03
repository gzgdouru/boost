#include "../public/headfile.hpp"
#include "boost/utility.hpp"
#include "boost/thread.hpp"
#include "boost/ref.hpp"
#include "boost/function.hpp"

using namespace boost;

template<typename T>
class basic_atom:public noncopyable
{
public:
	basic_atom(T x = T()) :n(x)
	{

	}

	T operator ++()
	{
		boost::mutex::scoped_lock lock(mu);
		return ++n;
	}

	operator T()
	{
		return n;
	}

	void show()
	{
		cout << n << endl;
	}

private:
	T n;
	boost::mutex mu;
};

typedef basic_atom<int> atom_int;

boost::mutex io_mu;
void printing(atom_int &x, const string &szStr)
{
	cout << szStr << "-";
	x.show();
	for (int i = 0; i < 5; ++i)
	{
		boost::mutex::scoped_lock lock(io_mu);
		cout << szStr << ":" << ++x << endl;
	}
}

void testOne()
{
	atom_int x;
	boost::thread th1(printing, boost::ref(x), "hello");
	boost::thread th2(printing, boost::ref(x), "boost");

	th1.timed_join(boost::posix_time::seconds(3));
	th2.join();

	// boost::this_thread::sleep(boost::posix_time::seconds(2));
}

void testTwo()
{
	atom_int x;
	atom_int y(5);
	x.show();
	y.show();

	boost::thread t3(bind(printing, boost::ref(x), "thread"));
	boost::function<void()> func = bind(printing, boost::ref(y), "mutex");
	boost::thread t4(func);
	t3.join();
	t4.join();

	x.show();
	y.show();
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	testTwo();

	getchar();

	return 0;
}