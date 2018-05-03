#include "../public/headfile.hpp"
#include "boost/swap.hpp"
using namespace std;

void swap_array()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18,19};

	cout << "swap befor:" << endl;
	cout << "a:";
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "b:";
	for (int i = 0; i < 10; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	boost::swap(a, b);

	cout << "swap after:" << endl;
	cout << "a:";
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "b:";
	for (int i = 0; i < 10; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
}

class point
{
public:
	explicit point(int a, int b, int c) :x(a), y(b), z(c) {}
	void print()
	{
		cout << "x:" << x << ",y:" << y << ",z:" << z << endl;
	}

	void swap(point &p)
	{
		std::swap(x, p.x);
		std::swap(y, p.y);
		std::swap(z, p.z);
		cout << "inner swap!" << endl;
	}

private:
	int x;
	int y;
	int z;
};

namespace boost
{
	void swap(point &x, point &y)
	{
		x.swap(y);
	}
}

int main(int argc, char *argv[])
{
	/*swap_array();*/

	point a(1, 2, 3);
	point b(4, 5, 6);
	cout << "std:swap:" << endl;
	std::swap(a, b);
	cout << "a:";
	a.print();
	cout << "b:";
	b.print();
	cout << endl;

	point c(1, 2, 3);
	point d(4, 5, 6);
	cout << "boost:swap:" << endl;
	boost::swap(c, d);
	cout << "c:";
	c.print();
	cout << "d:";
	d.print();
	cout << endl;

	getchar();

	return 0;
}