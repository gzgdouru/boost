#include "../public/headfile.hpp"
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/bind.hpp"
#include "boost/function.hpp"
using namespace boost::asio;

int main(int argc, char *argv[])
{
	try
	{
		cout << "server start..." << endl;

		io_service ios;

		ip::tcp::acceptor apt(ios, ip::tcp::endpoint(ip::tcp::v4(), 6688));
		cout << apt.local_endpoint().address() << endl;

		while (true)
		{
			ip::tcp::socket sock(ios);
			apt.accept(sock);

			cout << "client:";
			cout << sock.remote_endpoint().address() << endl;

			sock.write_some(boost::asio::buffer("hello asio"));
		}
	}
	catch (std::exception & e)
	{
		cout << e.what() << endl;
	}

	return 0;
}