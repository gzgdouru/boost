#include "../../cplusplus/public/headfile.hpp"
#include "boost/progress.hpp"

int main(int argc, char *argv[])
{
	{
		boost::progress_timer tTime;
		this_thread::sleep_for(chrono::milliseconds(5000));
	}

	return 0;
}
