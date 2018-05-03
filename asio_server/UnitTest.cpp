#include "../public/headfile.hpp"
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/thread.hpp"
using namespace boost::asio;

class asio_server
{
	typedef boost::shared_ptr<ip::tcp::socket> sock_ptr;

public:
	asio_server(io_service &io):
		ios(io),
		apt(ios, ip::tcp::endpoint(ip::tcp::v4(), 6688))
	{
		start();
	}

	void start()
	{
		sock_ptr sock(new ip::tcp::socket(ios));

		apt.async_accept(*sock, bind(&asio_server::accept_handler, this, _1, sock));

		cout << "hello hi" << endl;
	}

	void accept_handler(const boost::system::error_code& e, sock_ptr sock)
	{
		if (e)
		{
			return;
		}

		cout << "client:";
		cout << sock->remote_endpoint().address() << endl;
		sock->async_write_some(buffer("hello asio"), bind(&asio_server::write_handler, this, _1));

		start();
	}

	void write_handler(const boost::system::error_code &e)
	{
		this_thread::sleep(posix_time::milliseconds(200));
		cout << "send msg complete." << endl;
	}

private:
	io_service &ios;
	ip::tcp::acceptor apt;
};

int main(int argc, char *argv[])
{
	try
	{
		cout << "server start..." << endl;

		io_service ios;
		asio_server server(ios);
		ios.run();
	}
	catch (std::exception &e)
	{
		cout << e.what() << endl;
	}

	return 0;
}