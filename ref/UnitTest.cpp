#include "../public/headfile.hpp"
#include "boost/ref.hpp"

void testOne()
{
	int x = 10;
	boost::reference_wrapper<int> rw(x);
	cout << (x == rw) << endl;
	(int &)rw = 100;
	cout << rw << endl;

	boost::reference_wrapper<int> rw2(rw);
	cout << rw2.get() << endl;

	string szStr;
	boost::reference_wrapper<string> rw3(szStr);
	szStr = "hello gi";
	cout << rw3.get() << endl;

	*rw3.get_pointer() = "test reference_wrapper";
	cout << rw3.get().size() << endl;
	cout << szStr << endl;
}

void testTwo()
{
	double dNum = 2.0;
	std::sqrt(boost::ref(dNum));
	cout << dNum << endl;
}

class big_class
{
public:
	big_class() :x(0) {}
	void print()
	{
		cout << "big_class:" << ++x << endl;
	}

private:
	int x;
};

template<typename T>
void print(T a)
{
	for (int i = 0; i < 2; ++i)
	{
		boost::unwrap_ref(a).print();
	}
}

void testThree()
{
	big_class c;
	auto rw = boost::ref(c);

	c.print();

	print(c);
	print(rw);
	print(c);
	c.print();
}

void func(int x)
{
	++boost::unwrap_ref(x);
}

void testFour()
{
	int x = 0;
	func(x);
	cout << x << endl;
	func(boost::ref(x));
	cout << x << endl;

	auto rw = boost::ref(x);
	func(rw);
	cout << x << endl;
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	/*testThree();*/

	testFour();

	getchar();
	return 0;
}