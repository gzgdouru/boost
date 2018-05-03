#include "../public/headfile.hpp"
#include "boost/thread.hpp"

mutex io_mu;

class buffer
{
public:
	buffer(size_t n) :un_read(0), capacity(n) {}
	void put(int x);
	void get(int *x);

private:
	bool is_full()
	{
		return un_read == capacity;
	}

	bool is_empty()
	{
		return un_read == 0;
	}

private:
	mutex mu;
	boost::condition_variable_any cond_put;
	boost::condition_variable_any cond_get;
	stack<int> stk;
	int un_read;
	int capacity;
};

void buffer::put(int x)
{
	{
		boost::mutex::scoped_lock lock(mu);
		while (is_full())
		{
			{
				boost::mutex::scoped_lock lock(io_mu);
				cout << "full waiting..." << endl;
			}
			cond_put.wait(mu);
		}
		stk.push(x);
		++un_read;
	}

	cond_get.notify_all();
}

void buffer::get(int *x)
{
	{
		boost::mutex::scoped_lock lock(mu);
		while (is_empty())
		{
			{
				boost::mutex::scoped_lock lock(io_mu);
				cout << "empty waiting..." << endl;
			}
			cond_get.wait(mu);
		}
		*x = stk.top();
		--un_read;
	}

	cond_put.notify_all();
}

buffer buf(5);
void producer(int n)
{
	for (int i = 0; i < n; ++i)
	{
		{
			boost::mutex::scoped_lock lock(io_mu);
			cout << "put:" << i << endl;
		}
		buf.put(i);
		boost::this_thread::sleep(boost::posix_time::seconds(2));
	}

}

void consumer(int n)
{
	int x;
	for (int i = 0; i < n; ++i)
	{
		buf.get(&x);
		boost::mutex::scoped_lock lock(io_mu);
		cout << "get(" << boost::this_thread::get_id() << "):" << x << endl;
		boost::this_thread::sleep(boost::posix_time::seconds(1));
	}
}

int main(int argc, char *argv[])
{
	boost::thread th1(producer, 20);
	boost::thread th2(consumer, 10);
	boost::thread th3(consumer, 10);

	th1.join();
	th2.join();
	th3.join();

	getchar();
	return 0;
}