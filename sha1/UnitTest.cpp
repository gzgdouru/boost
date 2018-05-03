#include "../public/headfile.hpp"
#include "boost/uuid/sha1.hpp"
using namespace std;
using namespace boost::uuids::detail;

int main(int argc, char *argv[])
{
	sha1 sha;

	string szMessage = "a short message";

	sha.process_byte(0x10);
	sha.process_bytes((void*)szMessage.c_str(), szMessage.length());
	sha.process_block((void*)szMessage.c_str(), szMessage.c_str() + szMessage.length());

	unsigned int digest[5] = { 0 };
	sha.get_digest(digest);

	for (int i = 0; i < 21; ++i)
	{
		cout << hex << digest[i] << " ";
	}
	cout << endl;

	getchar();

	return 0;
}