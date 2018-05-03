#include "../public/headfile.hpp"
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread.hpp"
using namespace boost::asio;

class asio_client
{
	typedef boost::shared_ptr<ip::tcp::socket> sock_ptr;

public:
	asio_client(io_service &io) :
		ios(io),
		ep(ip::address::from_string("127.0.0.1"), 6688)
	{
		start();
	}

	void start()
	{
		sock_ptr sock(new ip::tcp::socket(ios));
		sock->async_connect(ep, bind(&asio_client::conn_handler, this, _1, sock));

		cout << "hello hi" << endl;
	}

	void conn_handler(const boost::system::error_code &e, sock_ptr sock)
	{
		if (e)
		{
			return;
		}

		cout << "recive from " << sock->local_endpoint().address() << endl;
		boost::shared_ptr<vector<char> > str(new vector<char>(100, 0));

		sock->async_read_some(buffer(*str), bind(&asio_client::read_handler, this, _1, str));

		start();
	}

	void read_handler(const boost::system::error_code &e, boost::shared_ptr<vector<char> > str)
	{
		if (e)
		{
			return;
		}
		
		this_thread::sleep(posix_time::seconds(5));
		cout << &(*str)[0] << endl;
	}

private:
	io_service &ios;
	ip::tcp::endpoint ep;
};

int main(int argc, char *argv[])
{
	try
	{
		cout << "client start..." << endl;
		io_service ios;
		asio_client client(ios);
		ios.run();
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}