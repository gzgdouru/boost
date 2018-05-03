#include "../public/headfile.hpp"
#include "../public/uuids.hpp"
#include "boost/lexical_cast.hpp"
using namespace std;
using namespace boost::uuids;

int main(int argc, char *argv[])
{
	uuid u;
	u = nil_generator()();
	cout << "uuid1:" << u << endl;

	uuid u2;
	u2 = string_generator()("01234567-89ab-cdef-0123-456789abcdef");
	cout << "uuid2:" << u2 << endl;

	uuid www_xxx_com = u2;
	uuid u3 = name_generator(www_xxx_com)("marion");
	cout << "uuid3:" << u3 << endl;

	uuid u4 = name_generator(www_xxx_com)("link");
	cout << "uuid4:" << u4 << endl;

	uuid u5 = random_generator()();
	cout << "uuid5:" << u5 << endl;

	uuid u6 = random_generator()();
	cout << "uuid6:" << u6 << endl;


	string szU6 = boost::lexical_cast<string>(u6);
	cout << "string u6:" << szU6 << endl;


	getchar();

	return 0;
}