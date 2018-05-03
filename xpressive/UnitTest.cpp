#include "../public/headfile.hpp"
#include "boost/xpressive/xpressive_dynamic.hpp"
using namespace boost::xpressive;

void testOne()
{
	cregex reg = cregex::compile("a.c");
	cout << regex_match("abc", reg) << endl;
	cout << regex_match("a+c", reg) << endl;

	cout << regex_match("ac", reg) << endl;
	cout << regex_match("abd", reg) << endl;
}

void testTwo()
{
	string szStr = "[0-9]{6}(1|2)[0-9]{3}(0|1)[0-9][0-3][0-9][0-9]{3}(X|[0-9])";	 // Éí·ÝÖ¤ºÅ

	cregex reg = cregex::compile(szStr, icase);
	cout << regex_match("999555197001019999", reg) << endl;
	cout << regex_match("99955519700101999X", reg) << endl;
	cout << regex_match("99955520100101999x", reg) << endl;

	cout << regex_match("99955520100101999Z", reg) << endl;
	cout << regex_match("99955530100101999x", reg) << endl;
	cout << regex_match("999555201021019998", reg) << endl;
	cout << regex_match("999555201001419991", reg) << endl;
}

void testThree()
{
	string szStr = "[0-9]{6}((1|2)[0-9]{3})((0|1)[0-9])([0-3][0-9])([0-9]{3}(X|[0-9]))";
	cregex reg = cregex::compile(szStr, icase);
	cmatch what;

	cout << regex_match("999555197001019999", what, reg) << endl;
	for (auto it = what.begin(); it != what.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;
	cout << "date:" << what[1] << "-" << what[3] << "-" << what[5] << endl;
}

void testFour()
{
	string szStr = "readme.txt";
	sregex reg = sregex::compile("^re.*");
	sregex reg2 = sregex::compile(".*.txt$");

	cout << regex_match(szStr, reg) << endl;
	cout << regex_match(szStr, reg2) << endl;
}

void testFive()
{
	string szStr = "there is a POWER-suit item";
	sregex reg = sregex::compile("(power)-(.{4})", icase);

	cout << regex_search(szStr, reg) << endl;

	smatch what;
	regex_search(szStr, what, reg);
	for (auto it = what.begin(); it != what.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;
}

void testSix()
{
	string szStr = "readme.txt";

	sregex reg = sregex::compile("(.*)(me)");
	sregex reg2 = sregex::compile("(t)(.)(t)");

	cout << regex_replace(szStr, reg, "manual") << endl;
	cout << regex_replace(szStr, reg, "$1you") << endl;
	cout << regex_replace(szStr, reg, "$&$&") << endl;
	cout << regex_replace(szStr, reg2, "$1N$3") << endl;

	szStr = regex_replace(szStr, reg2, "$1$3");
	cout << szStr << endl;
}

void testSeven()
{
	string szStr = "2010 Happy new year!!!";

	sregex reg = sregex::compile("^([0-9]| )*");
	sregex reg2 = sregex::compile("!*$");

	cout << regex_replace(szStr, reg, "") << endl;
	cout << regex_replace(szStr, reg2, "") << endl;

	szStr = regex_replace(szStr, reg, "Y2000 ");
	cout << szStr << endl;
}

void testEight()
{
	string szStr = "Power-bomb, power-suit, pOWER-beam all items";

	sregex reg = sregex::compile("power-([a-zA-Z]{4})", icase);

	sregex_iterator pos(szStr.begin(), szStr.end(), reg);
	sregex_iterator end;

	while (pos != end)
	{
		cout << "[" << (*pos)[0] << "] ";
		++pos;
	}
	cout << endl;
}

void testNine()
{
	char *pStr = "*Link*||+Mario+||Zelda!!!||Metroid";

	cregex reg = cregex::compile("\\w+", icase);
	cout << regex_match(pStr, pStr + strlen(pStr), reg) << endl;
	cregex_token_iterator pos(pStr, pStr + strlen(pStr), reg);
	while (pos != cregex_token_iterator())
	{
		cout << "[" << *pos << "] ";
		++pos;
	}
	cout << endl;

	cregex splitReg = cregex::compile("\\|\\|");
	pos = cregex_token_iterator(pStr, pStr + strlen(pStr), splitReg, -1);
	while (pos != cregex_token_iterator())
	{
		cout << "[" << *pos << "] ";
		++pos;
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	/*testOne();*/

	/*testTwo();*/

	/*testThree();*/

	/*testFour();*/

	//testFive();

	//testSix();

	//testSeven();

	/*testEight();*/

	testNine();

	getchar();
	return 0;
}