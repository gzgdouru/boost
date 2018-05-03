#include "../public/headfile.hpp"
#include "boost/lexical_cast.hpp"
using namespace std;
using namespace boost;

void testOne()
{
	int x = lexical_cast<int>("100");
	long y = lexical_cast<long>("2000");
	float pai = lexical_cast<float>("3.14159e5");
	double e = lexical_cast<double>("2.71828");
	cout << x << " " << y << " " << pai << " " << e << endl;

	string szStr = lexical_cast<string>(456);
	cout << szStr << endl;

	cout << lexical_cast<string>(0.618) << endl;
	cout << lexical_cast<string>(0x10) << endl;

	cout << lexical_cast<bool>("1") << endl;
}

template<typename T>
bool num_valid(const string &szNum)
{
	try
	{
		lexical_cast<T>(szNum.c_str());
		return true;
	}
	catch (bad_lexical_cast &e)
	{
		return false;
	}
}

void testTwo()
{
	string szStr = "hello word";
	if (num_valid<int>(szStr))
	{
		cout << lexical_cast<int>(szStr.c_str()) << endl;
	}
	else
	{
		cout << szStr << " is invalid num" << endl;
	}
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	testTwo();

	getchar();

	return 0;
}