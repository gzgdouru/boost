#include "../../cplusplus/public/headfile.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/gregorian/parsers.hpp"
namespace bg = boost::gregorian;

// ��ȡ��ǰʱ��
void test1()
{
	// ���ر�������
	bg::date d = bg::day_clock::local_day();
	cout << d << endl;
	/*cout << bg::day_clock::local_day() << endl;*/

	// ����UTC����
	cout << bg::day_clock::universal_day() << endl;
}

// ��������
void test2()
{
	bg::date d(2018, 1, 29);
	cout << d.year() << endl;
	cout << d.month() << endl;
	cout << d.day() << endl;
	cout << "-" << endl;

	bg::date::ymd_type ymd = d.year_month_day();
	cout << ymd.year << endl;
	cout << ymd.month << endl;
	cout << ymd.day << endl;
	cout << "-" << endl;

	cout << d.day_of_week() << endl;	// �������ڼ�
	cout << d.day_of_year() << endl;	// ����һ���еĵڼ���
	bg::date lastDate = d.end_of_month();	// ���ص��µ����һ��
	cout << lastDate << endl;
	cout << d.week_number() << endl;	// ����һ���еĵڼ�������
}

// �������
void test3()
{
	bg::date d(2018, 1, 29);
	cout << bg::to_simple_string(d) << endl;
	cout << bg::to_iso_string(d) << endl;
	cout << bg::to_iso_extended_string(d) << endl;
}

// ��tm�ṹ��ת��
void test4()
{
	bg::date d(2018, 1, 29);
	tm t = bg::to_tm(d);
	cout << t.tm_year + 1900 << " " << t.tm_mon + 1 << " " << t.tm_mday << endl;

	bg::date d2 = bg::date_from_tm(t);
	cout << d2 << endl;
}

// ���ڳ���
void test5()
{
	bg::days dd1(10), dd2(-100), dd3(255);
	cout << (dd1 > dd2 && dd1 < dd3) << endl;
	cout << ((dd1 + dd2) == bg::days(-90)) << endl;
	cout << (dd1 + dd3).days() << endl;
	cout << (dd3 / 5).days() << endl;

	bg::weeks w(3);
	cout << w.days() << endl;

	bg::months m(5);
	bg::years y(2);
	bg::months m2 = y + m;
	cout << m2.number_of_months() << endl;
	cout << (y * 2).number_of_years() << endl;
}

// ��������
void test6()
{
	bg::date d1(2000, 1, 1);
	bg::date d2(2008, 8, 8);
	cout << d2 - d1 << endl;

	cout << d1 + bg::days(10) << endl;
	cout << d1 + bg::months(12) << endl;
	cout << d1 - bg::weeks(1) << endl;

	// ��ĩ����
	bg::date d(2010, 3, 30);
	d -= bg::months(1);
	cout << d << endl;
	d -= bg::months(1);
	cout << d << endl;
	d += bg::months(2);
	cout << d << endl;
}

// ��������
void test7()
{
	bg::date_period dp(bg::date(2010, 1, 1), bg::days(20));
	cout << dp.is_null() << endl;
	cout << dp.begin().day() << endl;
	cout << dp.last().day() << endl;
	cout << dp.end().day() << endl;
	cout << dp.length().days() << endl;
	cout << "-" << endl;

	bg::date_period dp1(bg::date(2010, 1, 1), bg::days(20));
	bg::date_period dp2(bg::date(2010, 2, 19), bg::days(10));
	cout << dp1 << endl;
	cout << dp2 << endl;
	cout << (dp1 < dp2) << endl;
}

// ������������
void test8()
{
	bg::date_period dp(bg::date(2010, 1, 1), bg::days(20));

	dp.shift(bg::days(3));
	cout << dp.begin().day() << endl;
	cout << dp.length().days() << endl;

	dp.expand(bg::days(3));
	cout << dp.begin().day() << endl;
	cout << dp.length().days() << endl;
	
	cout << "-" << endl;

	bg::date_period dp1(bg::date(2010, 1, 1), bg::days(20));
	cout << dp1.is_before(bg::date(2009, 12, 1)) << endl;
	cout << dp1.is_after(bg::date(2010, 2, 1)) << endl;
	cout << dp1.contains(bg::date(2010, 1, 10)) << endl;	//�ж��Ƿ����

	bg::date_period dp2(bg::date(2010, 1, 5), bg::days(10));
	cout << dp1.contains(dp2) << endl;
	cout << dp1.intersects(dp2) << endl;	// �ж��Ƿ��н���
	cout << dp1.intersection(dp2) << endl;	// ����������������Ľ���

	bg::date_period dp3(bg::date(2010, 1, 21), bg::days(5));
	cout << dp3.intersects(dp2) << endl;
	cout << (dp3.intersection(dp2)).is_null() << endl;
	cout << dp.is_adjacent(dp3) << endl;	// �ж��������������Ƿ�����
}

// ��������ϲ�
void test9()
{
	bg::date_period dp1(bg::date(2010, 1, 1), bg::days(20));
	bg::date_period dp2(bg::date(2010, 1, 5), bg::days(10));
	bg::date_period dp3(bg::date(2010, 2, 1), bg::days(5));
	bg::date_period dp4(bg::date(2010, 1, 15), bg::days(10));

	cout << dp1.merge(dp2) << endl;
	cout << dp1.merge(dp3).is_null() << endl;
	cout << dp1.merge(dp4) << endl;
	cout << dp1.span(dp3) << endl;
}

//���ڵ�����
void test10()
{
	bg::date d(2006, 11, 26);
	bg::day_iterator d_iter(d);	// ��������Ĭ��Ϊһ��

	assert(d_iter == d);
	++d_iter;
	cout << *d_iter << endl;

	bg::year_iterator y_iter(*d_iter, 3);	// ��������Ϊ����
	++y_iter;
	cout << y_iter->year() << endl;
}

// ��̬����
void test11()
{
	cout << bg::gregorian_calendar::is_leap_year(2036) << endl;	// �ж��Ƿ�����
	cout << bg::gregorian_calendar::end_of_month_day(2010, 2) << endl;	// ������ݺ��·�,������µ����һ��
}

// ��ʾ����
void test12(const string &szDate)
{
	bg::date d = bg::from_simple_string(szDate);
	bg::date d_start(d.year(), d.month(), 1);
	bg::date d_end(d.end_of_month());
	for (bg::day_iterator d_iter(d_start); d_iter != d_end; ++d_iter)
	{
		cout << *d_iter << " " << d_iter->day_of_week() << endl;
	}
}

//�����������,�������ʮ���������ж�����,�����ڼ�,�����ж��ٸ�������,�����ж�����
void test13(const string &szDate)
{
	bg::date d = bg::from_simple_string(szDate);
	bg::date d18years = d + bg::years(18);
	cout << "18 years total days: " << d18years - d << endl;

	cout << "d18years is " << d18years.day_of_week() << endl;

	int iCount = 0;
	bg::date d_begin(d18years.year(), d18years.month(), 1);
	bg::date d_end(d18years.end_of_month());
	for (bg::day_iterator d_iter(d_begin); d_iter != d_end; ++d_iter)
	{
		if (d_iter->day_of_week() == bg::Sunday)
		{
			++iCount;
		}
	}
	cout << "total " << iCount << " Sundays." << endl;

	iCount = (bg::gregorian_calendar::is_leap_year(d18years.year()) ? 366 : 365);
	cout << "d18years total " << iCount << " days" << endl;
}


class credit_card	// ���ÿ���
{
public:
	credit_card(const string &szBankName, int iBillDayNo):
		bank_name(szBankName), bill_day_no(iBillDayNo)
	{}

	// ������Ϣ��
	int calc_free_days(bg::date consume_day = bg::day_clock::local_day()) const
	{
		bg::date bill_day(consume_day.year(), consume_day.month(), bill_day_no);
		if (consume_day > bill_day)
		{
			bill_day += bg::months(1);
		}

		return (bill_day - consume_day).days() + 20;
	}

	bool operator<(const credit_card &other) const
	{
		return this->calc_free_days() < other.calc_free_days();
	}

public:
	string bank_name;	// ��������
	int bill_day_no;	// ������
};

// �������ÿ���Ϣ��
void test14()
{
	credit_card card1("A bank", 25);
	credit_card card2("B bank", 28);
	credit_card tmp = max(card1, card2);
	cout << tmp.bank_name << " " << tmp.calc_free_days() << endl;
}

int main(int argc, char *argv[])
{
	string szData = "2018-01-30";
	//test13(szData);
	
	test14();
	
	return 0;
}