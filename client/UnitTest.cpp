#include "../public/headfile.hpp"
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
using namespace boost::asio;

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
		t.expires_at(t.expires_at() + posix_time::milliseconds(2000));
		t.async_wait(bind(&a_timer::call_func, this, _1));
	}

private:
	int count;
	int count_max;
	boost::function<void()> f;
	deadline_timer t;
};

void client(io_service &ios)
{
	try
	{
		cout << "client start..." << endl;

		ip::tcp::socket sock(ios);
		ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 6688);

		sock.connect(ep);

		vector<char> str(100, 0);
		sock.read_some(boost::asio::buffer(str));
		cout << "recive from " << sock.remote_endpoint().address();
		cout << " " << &str[0] << endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
}

void testOne()
{
	io_service ios;
	a_timer at(ios, 5, bind(client, boost::ref(ios)));

	ios.run();
}

#include "boost/lexical_cast.hpp"
void resolv_connect(ip::tcp::socket &sock, const string &name, int port)
{
	ip::tcp::resolver rlv(sock.get_io_service());
	ip::tcp::resolver::query qry(name.c_str(), lexical_cast<string>(port));

	ip::tcp::resolver::iterator iter = rlv.resolve(qry);
	ip::tcp::resolver::iterator end;
	boost::system::error_code code = error::host_not_found;
	for (; code && iter != end; ++iter)
	{
		sock.close();
		cout << iter->endpoint().address() << endl;
		sock.connect(*iter, code);
	}

	if (code)
	{
		cout << "can't connect." << endl;
		throw boost::system::error_code(code);
	}

	cout << "connect success." << endl;
}

void testTwo()
{
	try
	{
		io_service ios;
		ip::tcp::socket sock(ios);
		resolv_connect(sock, "baidu.com", 80);

		ios.run();
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}
}

int main(int argc, char *argv[])
{
	testTwo();

	getchar();
	return 0;
}