#include "../public/headfile.hpp"
#include "boost/tokenizer.hpp"
using namespace boost;

void testOne()
{
	string szStr = "Link raise the master-sword.";
	
	boost::tokenizer<> tok(szStr);
	for (auto pos = tok.begin(); pos != tok.end(); ++pos)
	{
		cout << "[" << *pos << "] ";
	}
	cout << endl;
}

void testTwo()
{
	char *pStr = "Link ;; <master-sword> zelda";

	boost::char_separator<char> sep;
	int iSize = strlen(pStr);
	boost::tokenizer<char_separator<char>, char*> tok(pStr, pStr + iSize, sep);
	printSTL(tok);

	tok.assign(pStr, pStr + iSize, boost::char_separator<char>(" ;-", "<>"));
	printSTL(tok);

	tok.assign(pStr, pStr + iSize, char_separator<char>(" ;-<>", "", keep_empty_tokens));
	printSTL(tok);
}

void testThree()
{
	string szStr = "id,100,name,\"marior\"";
	
	escaped_list_separator<char> sep;
	tokenizer<escaped_list_separator<char> > tok(szStr, sep);
	printSTL(tok);
}

void testFour()
{
	string szStr = "1111111111";
	int offsets[] = { 2, 3, 4 };
	offset_separator sep(offsets, offsets + 3, true, false);
	tokenizer<offset_separator> tok(szStr, sep);
	printSTL(tok);

	tok.assign(szStr, offset_separator(offsets, offsets + 3, false));
	printSTL(tok);

	szStr += "11677";
	tok.assign(szStr, offset_separator(offsets, offsets + 3, true, false));
	printSTL(tok);
}

int main(int argc, char *argv[])
{
	//testOne();

	/*testTwo();*/

	//testThree();

	testFour();

	getchar();
	return 0;
}