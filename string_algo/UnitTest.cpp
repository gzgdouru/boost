#include "../public/headfile.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/format.hpp"
using namespace std;
using namespace boost;

void StringConvert()
{
	string szStr = "i don't KONW!";
	cout << "to_upper_copy: " << boost::to_upper_copy(szStr) << endl;
	cout << "source str: " << szStr << endl;

	boost::to_lower(szStr);
	cout << "source str: " << szStr << endl;
}

void Algorithm()
{
	string szStr = "Power Bomb";

	cout << boost::iends_with(szStr, "bomb") << endl;
	cout << boost::ends_with(szStr, "bomb") << endl;

	cout << boost::istarts_with(szStr, "pow") << endl;

	cout << boost::contains(szStr, "er") << endl;

	string szStr2 = to_upper_copy(szStr);
	cout << boost::iequals(szStr, szStr2) << endl;

	string szStr3 = "power suit";
	cout << boost::ilexicographical_compare(szStr, szStr3) << endl;

	cout << boost::all(szStr2.substr(0, 5), is_lower()) << endl;;
}

void FunctionObject()
{
	string szStr = "Samus";
	string szStr2 = "samus";

	cout << boost::is_equal()(szStr, szStr2) << endl;
	cout << boost::is_less()(szStr, szStr2) << endl;
}

void StringTrim()
{
	boost::format fmt("|%s|");

	string szStr = " samus aran ";
	cout << fmt % boost::trim_copy(szStr) << endl;
	cout << fmt % boost::trim_left_copy(szStr) << endl;

	boost::trim_right(szStr);
	cout << fmt % szStr << endl;

	string szStr2 = "2017 happy new year!!!";
	cout << fmt % boost::trim_left_copy_if(szStr2, is_digit()) << endl;
	cout << fmt % boost::trim_right_copy_if(szStr2, is_punct()) << endl;

	cout << fmt % boost::trim_copy_if(szStr2, is_punct() || is_digit() || is_space()) << endl;
}

void StringFind()
{
	boost::format fmt("|%s|.pos = %d\n");

	string szStr = "Long long ago, there was a king.";
	/*boost::iterator_range<string::iterator> rge;*/

	auto rge = boost::find_first(szStr, "long");
	cout << fmt % rge % (rge.begin() - szStr.begin());

	rge = boost::ifind_first(szStr, "long");
	cout << fmt % rge % (rge.begin() - szStr.begin());

	rge = boost::find_nth(szStr, "ng", 2);
	cout << fmt % rge % (rge.begin() - szStr.begin());

	rge = boost::find_head(szStr, 4);
	cout << fmt % rge % (rge.begin() - szStr.begin());

	rge = boost::find_tail(szStr, 5);
	cout << fmt % rge % (rge.begin() - szStr.begin());

	rge = boost::find_first(szStr, "samus");
	cout << rge.empty() << endl;
}

void ReplaceAndErase()
{
	string szStr = "Samus beat the monster.\n";

	cout << boost::replace_first_copy(szStr, "Samus", "samus");

	boost::replace_last(szStr, "beat", "kill");
	cout << szStr;

	boost::replace_tail(szStr, 9, "ridley.\n");
	cout << szStr;

	cout << boost::ierase_all_copy(szStr, "samus");
	cout << boost::replace_nth_copy(szStr, "l", 1, "L");
	cout << boost::erase_tail_copy(szStr, 8);
}

void StringSplit()
{
	string szStr = "Samus,Link,Zelda::Mario-Luigi+zelda";

	deque<string> deStr;
	boost::ifind_all(deStr, szStr, "zELDA");
	for (auto it = deStr.begin(); it != deStr.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;

	list<string> lstStr;
	boost::split(lstStr, szStr, boost::is_any_of(",.:-+"));
	for (auto it = lstStr.begin(); it != lstStr.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;

	lstStr.clear();
	boost::split(lstStr, szStr, boost::is_any_of(".:-"), boost::token_compress_on);
	for (auto it = lstStr.begin(); it != lstStr.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;
}

void StringJoin()
{
	vector<string> vtStr{ "Samus", "Link", "Zelda", "Mario" };
	cout << boost::join(vtStr, "-") << endl;

	struct is_contains_a
	{
		bool operator()(const string &szFlag)
		{
			return boost::contains(szFlag, "a");
		}
	};

	cout << boost::join_if(vtStr, "**", is_contains_a()) << endl;
}

void StringIterator()
{
	string szStr = "Samus||samus||mario||Link";

	boost::find_iterator<string::iterator> pos, end;
	for (pos = boost::make_find_iterator(szStr, boost::first_finder("samus", boost::is_iequal())); pos != end; ++pos)
	{
		cout << "[" << *pos << "] ";
	}
	cout << endl;

	boost::split_iterator<string::iterator> p, endp;
	for (p = boost::make_split_iterator(szStr, boost::first_finder("||", is_equal())); p != endp; ++p)
	{
		cout << "[" << *p << "] ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	//StringConvert();

	//Algorithm();

	//FunctionObject();

	/*StringTrim();*/

	/*StringFind();*/

	/*ReplaceAndErase();*/

	/*StringSplit();*/

	/*StringJoin();*/

	StringIterator();

	getchar();
	return 0;
}