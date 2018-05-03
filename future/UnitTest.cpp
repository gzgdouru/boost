#include "../public/headfile.hpp"
#include "boost/thread.hpp"
#include "boost/array.hpp"
#include "boost/foreach.hpp"

int fab(int x)
{
	if (x == 0 || x == 1)
	{
		return 1;
	}
	return fab(x - 1) + fab(x - 2);
}

void testOne()
{
	boost::packaged_task<int> pt(bind(fab, 10));

	boost::unique_future<int> uf = pt.get_future();

	thread th1(boost::move(pt));
	uf.wait();

	if (uf.is_ready() && uf.has_value())
	{
		cout << uf.get() << endl;
	}
}

void testTwo()
{
	typedef boost::packaged_task<int> pt_t;
	typedef boost::unique_future<int> ut_t;

	boost::array<pt_t, 5> ap;
	boost::array<ut_t, 5> au;
	for (int i = 0; i < 5; ++i)
	{
		ap[i] = pt_t(bind(fab, i + 10));
		au[i] = ap[i].get_future();
		boost::thread(boost::move(ap[i]));
	}

	/*wait_for_all(au.begin(), au.end());*/
	wait_for_any(au[4], au[2], au[3]);
	
	for(auto &uf:au)
	{
		if (uf.is_ready() && uf.has_value())
		{
			cout << uf.get() << endl;
		}
	}
}

void fabs(int n, promise<int> *p)
{
	p->set_value(n);
}

void testThree()
{
	promise<int> p;
	boost::unique_future<int> uf = p.get_future();

	thread(fabs, 1000, &p);

	uf.wait();
	cout << uf.get() << endl;
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	//testTwo();

	testThree();

	getchar();
	return 0;
}