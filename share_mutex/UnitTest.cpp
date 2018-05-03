#include "../public/headfile.hpp"
#include "boost/thread.hpp"

boost::mutex io_mu;

class rw_data
{
public:
	rw_data() :m_x(0) {}
	void wirte()
	{
		unique_lock<shared_mutex> ul(rw_mu);
		++m_x;
	}

	void read(int *x)
	{
		shared_lock<shared_mutex> sl(rw_mu);
		*x = m_x;
	}

public:
	int m_x;
	boost::shared_mutex rw_mu;
};

void writer(rw_data &data)
{
	for (int i = 0; i < 20; ++i)
	{
		this_thread::sleep(posix_time::milliseconds(200));
		data.wirte();
		boost::mutex::scoped_lock lock(io_mu);
		cout << "wirte(" << this_thread::get_id() << "):" << data.m_x << endl;
	}
}

void reader(rw_data &data)
{
	int x;
	for (int i = 0; i < 10; ++i)
	{
		this_thread::sleep(posix_time::milliseconds(1000));
		data.read(&x);
		boost::mutex::scoped_lock lock(io_mu);
		cout << "read(" << this_thread::get_id() << "):" << x << endl;
	}

}

int main(int argc, char *argv[])
{
	rw_data data;
	thread_group pool;

	/*pool.create_thread(bind(reader, boost::ref(data)));
	pool.create_thread(bind(reader, boost::ref(data)));
	pool.create_thread(bind(reader, boost::ref(data)));
	pool.create_thread(bind(reader, boost::ref(data)));*/
	pool.create_thread(bind(writer, boost::ref(data)));
	pool.create_thread(bind(writer, boost::ref(data)));

	pool.join_all();

	getchar();
	return 0;
}