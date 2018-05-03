#include "../public/headfile.hpp"
#include "boost/function.hpp"
#include "boost/bind.hpp"

int fadd(int a, int b)
{
	return a + b;
}

void testOne()
{
	boost::function<int(int, int)> func;
	cout << func << endl;

	func = fadd;
	if (func)
	{
		cout << func(10, 20) << endl;;
	}

	func.clear();
	cout << func << endl;
}

struct demo_class
{
	typedef int result_type;

	int add(int a, int b)
	{
		return a + b;
	}

	int operator()(int x) const
	{
		return x * x;
	}
};

void testTwo()
{
	boost::function<int (demo_class&, int, int)> func1;
	func1 = bind(&demo_class::add, _1, _2, _3);
	demo_class sc;
	cout << func1(sc, 10, 20) << endl;

	boost::function<int(int, int)> func2;
	func2 = bind(&demo_class::add, &sc, _1, _2);
	cout << func2(10, 20) << endl;

	boost::function<int(int)> func3;
	func3 = bind(sc, _1);
	cout << func3(10) << endl;
}

template<typename T>
struct summary
{
	typedef void result_type;
	T sum;
	summary(T v = T()) :sum(v) {}
	void operator()(const T& x)
	{
		sum += x;
	}
};

void testThree()
{
	vector<int> vtInt = { 1, 3, 5, 7, 9 };
	summary<int> s;
	boost::function<void(const int&)> func(boost::ref(s));
	for_each(vtInt.begin(), vtInt.end(), func);
	cout << s.sum << endl;
}

class call_back
{
public:
	call_back(int i) :n(i) {}

	template<typename callback>
	void accept(callback f)
	{
		func = f;
	}

	void run()
	{
		func(n);
	}

private:
	typedef boost::function<void(int)> func_t;
	func_t func;
	int n;
};

void call_back_func(int x)
{
	cout << "call_back_func:" << x * 2 << endl;
}

void testFour()
{
	call_back cb(10);
	cb.accept(call_back_func);
	cb.run();
}

class call_back_obj
{
public:
	call_back_obj(int a) :x(a) {}
	void operator()(int i)
	{
		cout << "call_back_obj:" << i * x++ << endl;
	}

private:
	int x;
};

void testFive()
{
	call_back cd(10);
	call_back_obj cbo(2);
	cd.accept(boost::ref(cbo));
	cd.run();
	cd.run();
}

class call_back_factory
{
public:
	void call_back_func1(int i)
	{
		cout << "call_back_func1:" << i * 2 << endl;
	}

	void call_back_func2(int i, int j)
	{
		cout << "call_back_func2:" << i * j * 2 << endl;
	}
};

void testSix()
{
	call_back cb(10);
	call_back_factory cbf;
	cb.accept(bind(&call_back_factory::call_back_func1, &cbf, _1));
	cb.run();
	cb.accept(bind(&call_back_factory::call_back_func2, &cbf, 5, 5));
	cb.run();
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	/*testThree();*/

	//testFour();

	/*testFive();*/

	testSix();

	getchar();
	return 0;
}