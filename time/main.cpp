#include "../../cplusplus/public/headfile.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

// 操作时间长度
void test1()
{
	namespace pt = boost::posix_time;
	pt::time_duration td(1, 10, 30, 1000);
	cout << td << endl;

	// 超出的范围会自动进位
	pt::time_duration td2(1, 60, 60, 1000 * 1000 * 6 + 1000);
	cout << td2 << endl;

	pt::hours h(1);
	pt::minutes m(10);
	pt::seconds s(30);
	pt::millisec ms(1);
	pt::time_duration td3 = h + m + s + ms;
	cout << td3 << endl;

	pt::time_duration td4 = pt::duration_from_string("1:10:30:001");
	cout << td4 << endl;

	pt::time_duration td5(1, 10, 30, 1000);
	cout << td5.hours() << " " << td5.minutes() << " " << td5.seconds() << endl;
	cout << td5.total_seconds() << endl;	// 返回总秒数
	cout << td5.total_milliseconds() << endl;	// 返回总微秒数
	cout << pt::to_simple_string(td5) << endl;
	cout << pt::to_iso_string(td5) << endl;
}

// 创建时间点对象
void test2()
{
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	ptime p(date(2010, 3, 5), hours(1));
	cout << p << endl;

	ptime p1 = time_from_string("2010-03-05 01:00:00");
	cout << p1 << endl;

	ptime p2 = from_iso_string("20100305T010000");
	cout << p2 << endl;

	ptime p3 = second_clock::local_time();
	cout << p3 << endl;

	ptime p4 = microsec_clock::universal_time();
	cout << p4 << endl;
}

// 操作时间点对象
void test3()
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	ptime p(date(2018, 1, 30), hours(16) + minutes(8));
	cout << p << endl;

	date d = p.date();
	time_duration td = p.time_of_day();
	cout << d << endl;
	cout << td << endl;

	ptime p1(date(2010, 3, 20), hours(12) + minutes(30));
	ptime p2 = p1 + hours(3);
	cout << (p2 > p1) << endl;
	cout << (p2 - p1) << endl;
	p2 += months(4);
	cout << p2.date().month() << endl;

	ptime p3 = second_clock::local_time();
	cout << to_simple_string(p3) << endl;
	cout << to_iso_string(p3) << endl;
	cout << to_iso_extended_string(p3) << endl;
}

// 与tm,time_t等结构的转换
void test4()
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	ptime p = second_clock::local_time();
	tm t = to_tm(p);
	cout << t.tm_year + 1900 << " " << t.tm_mon + 1 << " " << t.tm_mday << " "
		<< t.tm_hour << " " << t.tm_min << " " << t.tm_sec << endl;

	ptime p2 = from_time_t(time(0));
	cout << p2 << endl;
}

// 时间区间
void test5()
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;
	
	ptime p(date(2010, 1, 1), hours(12));
	time_period tp1(p, hours(8));
	cout << tp1 << endl;

	time_period tp2(p + hours(8), hours(1));
	cout << tp2 << endl;

	cout << (tp1.end() == tp2.begin() && tp1.is_adjacent(tp2)) << endl;
	cout << tp1.intersects(tp2) << endl;

	tp1.shift(hours(1));
	cout << tp1.is_after(p) << endl;
	cout << tp1.intersects(tp2) << endl;

	tp2.expand(hours(10));
	cout << tp2 << endl;
	cout << (tp2.contains(p) && tp2.contains(tp1)) << endl;
}

// 时间迭代器
void test6()
{
	using namespace boost::gregorian;
	using namespace boost::posix_time;

	ptime p(date(2010, 2, 27), hours(10));
	for (time_iterator timeTter(p, minutes(10)); timeTter < p + hours(1); ++timeTter)
	{
		cout << *timeTter << endl;
	}
}

//高精度计时器
using namespace boost::gregorian;
using namespace boost::posix_time;
template<typename Clock = microsec_clock>
class basic_ptimer
{
public:
	basic_ptimer()
	{
		reset();
	}

	~basic_ptimer()
	{
		elapsed();
	}

	void reset()
	{
		m_startTime = Clock::local_time();
	}

	void elapsed() const 
	{
		cout << (Clock::local_time() - m_startTime) << endl;
	}

private:
	ptime m_startTime;
};
typedef basic_ptimer<microsec_clock> ptimer;
typedef basic_ptimer<second_clock> sptimer;

void test7()
{
	ptimer t;
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main(int argc, char *argv[])
{
	test7();
	return 0;
}