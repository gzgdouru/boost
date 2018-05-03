#include "../public/headfile.hpp"
#include "boost/bind.hpp"

int f(int a, int b)
{
	return a + b;
}

int g(int a, int b, int c)
{
	return a + b * c;
}

typedef int (*f_type)(int, int);
typedef int (*g_type)(int, int, int);

void testOne()
{
	cout << bind(f, 1, 2)() << endl;
	cout << bind(g, 1, 2, 3)() << endl;
}

void testTwo()
{
	int x = 1, y = 2, z = 3;
	cout << bind(f, _1, 9)(x) << endl;
	cout << bind(f, _1, _2)(x, y) << endl;
	cout << bind(f, _2, _1)(x, y) << endl;
	cout << bind(f, _1, _1)(x, y) << endl;
	cout << bind(g, _1, 8, _2)(x, y) << endl;
	cout << bind(g, _3, _2, _2)(x, y , z) << endl;
}

void testThree()
{
	f_type pf = f;
	g_type pg = g;
	int x = 1, y = 2, z = 3;
	cout << bind(pf, _1, 9)(x, y, z) << endl;
	cout << bind(pg, _3, _2, _2)(x, y, z) << endl;
}

struct demo
{
	int f(int x, int y)
	{
		return x * y;
	}
};

void testFour()
{
	int x = 5, y = 7;
	demo a, &ra = a;
	demo *p = &a;
	cout << bind(&demo::f, a, _1, _2)(x, y) << endl;
	cout << bind(&demo::f, ra, _1, _2)(x, y) << endl;
	cout << bind(&demo::f, p, _1, _2)(x, y) << endl;
}

struct point
{
	int x;
	int y;
	point(int a = 0, int b = 0) :x(a), y(b) {}
	void print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
};

void testFive()
{
	vector<point> vtPoint(10);
	for_each(vtPoint.begin(), vtPoint.end(), bind(&point::print, _1));
}

void testSix()
{
	vector<point> vtPoint = { {1,1},{2,2},{0,3},{10,4},{12,5} };
	vector<int> vtInt(vtPoint.size());
	transform(vtPoint.begin(), vtPoint.end(), vtInt.begin(), bind(&point::x, _1));
	printSTL(vtInt);
}

template<typename T>
void printNext(T x)
{
	++x;
}

void testSeven()
{
	int x = 5;
	bind(printNext<int>, _1)(x);
	cout << x << endl; 

	bind(printNext<int&>, _1)(boost::ref(x));
	cout << x << endl;
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	/*testThree();*/

	/*testFour();*/

	/*testFive();*/

	/*testSix();*/

	testSeven();

	getchar();
	return 0;
}