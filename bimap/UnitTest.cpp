#include "../public/headfile.hpp"
#include "boost/bimap.hpp"
#include "boost/bimap/unordered_multiset_of.hpp"
#include "boost/bimap/support/lambda.hpp"
using namespace boost;
using namespace boost::bimaps;

void testOne()
{
	bimap<int, string> bmap;
	bmap.left.insert(make_pair(1, "one"));
	bmap.left.insert(make_pair(2, "two"));

	bmap.right.insert(make_pair("ten", 10));
	bmap.right.insert(make_pair("six", 6));

	for (auto it = bmap.left.begin(); it != bmap.left.end(); ++it)
	{
		cout << "left[" << it->first << "] = " << it->second << endl;
	}

	for (auto it = bmap.right.begin(); it != bmap.right.end(); ++it)
	{
		cout << "right[" << it->first << "] = " << it->second << endl;
	}
}

void testTwo()
{
	bimap<unordered_multiset_of<int>, unordered_multiset_of<string> > bmap;

	bmap.left.insert(make_pair(1, "111"));
	bmap.left.insert(make_pair(2, "222"));
	bmap.left.insert(make_pair(2, "555"));

	bmap.right.insert(make_pair("string", 10));
	bmap.right.insert(make_pair("bimap", 20));
	bmap.right.insert(make_pair("bimap", 2));

	printMap(bmap.left, "left:");

	printMap(bmap.right, "right:");
}

void testThree()
{
	bimap<tagged<int, struct id>, tagged<string, struct name> > bmap;
	bmap.by<id>().insert(make_pair(1, "samus"));
	bmap.by<id>().insert(make_pair(2, "adam"));

	bmap.by<name>().insert(make_pair("link", 10));
	bmap.by<name>().insert(make_pair("zelda", 11));

	printMap(bmap.left, "left");
	printMap(bmap.right, "right");
}

void testFour()
{
	bimap<int, string> bmap;
	bmap.left.insert(make_pair(1, "mario"));
	bmap.left.insert(make_pair(2, "peach"));
	auto pos = bmap.left.find(1);
	cout << pos->first << "-" << pos->second << endl;
	auto pos2 = bmap.right.find("peach");
	cout << pos2->first << "-" << pos2->second << endl;

	bmap.left.replace_key(pos, 2);
	bmap.left.replace_data(pos, "luigi");

	printMap(bmap.left);

	bmap.left.modify_key(pos, _key = 2);
	printMap(bmap.left);
}

void testFive()
{
	bimap<int, string> bmap;
	bmap.left.insert(make_pair(3, "333"));
	auto left_pos = bmap.left.find(3);
	auto right_pos = bmap.project_right(left_pos);
	cout << right_pos->first << "-" << right_pos->second << endl;
}

int main(int argc, char *argv[])
{
	//testOne();

	/*testTwo();*/

	/*testThree();*/

	/*testFour();*/

	testFive();

	getchar();
	return 0;
}