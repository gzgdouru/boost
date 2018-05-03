#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <deque>
#include <cstdlib>
#include <stack>
#include <queue>
#include "boost/assign.hpp"
using namespace std;

void AddAndEqual()
{
	using namespace boost::assign;

	vector<int> vtInt;
	vtInt += 1, 2, 3, 4, 5, 6 * 6;
	cout << "vector<int>:" << endl;
	for (auto it = vtInt.begin(); it != vtInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<string> stStr;
	stStr += "cpp", "java", "c#", "python";
	cout << "set<string>:" << endl;
	for (auto it = stStr.begin(); it != stStr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	map<int, string> mptest;
	mptest += make_pair(1, "one"), make_pair(2, "two");
	cout << "map<int, string>:" << endl;
	for (auto it = mptest.begin(); it != mptest.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void parenthesis()
{
	using namespace boost::assign;

	vector<int> vtInt;
	push_back(vtInt) (1) (2) (3) (4) (5) (6 * 6);
	cout << "vector<int>:" << endl;
	for (auto it = vtInt.begin(); it != vtInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	list<string> lstStr;
	push_front(lstStr) ("cpp") ("java") ("c#") ("python");
	cout << "list<string>:" << endl;
	for (auto it = lstStr.begin(); it != lstStr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<double> stDou;
	insert(stDou) (3.14) (0.618) (1.732);
	cout << "set<double>:" << endl;
	for (auto it = stDou.begin(); it != stDou.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;


	map<int, string> mptest;
	insert(mptest) (1, "one") (2, "two");
	cout << "map<int, string>:" << endl;
	for (auto it = mptest.begin(); it != mptest.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void List_Of()
{
	using namespace boost::assign;

	vector<int> vtInt = boost::assign::list_of(1) (2) (3) (4) (5);
	cout << "vector<int>:" << endl;
	for (auto it = vtInt.begin(); it != vtInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	deque<string> deStr = (list_of("power") ("bomb"), "phazon", "suit");
	cout << "deque<string>:" << endl;
	for (auto it = deStr.begin(); it != deStr.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	set<int> stInt = (list_of(10), 20, 30, 40, 50);
	cout << "set<int>:" << endl;
	for (auto it = stInt.begin(); it != stInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	map<int, string> mptest = list_of(make_pair(1, "one")) (make_pair(2, "two"));
	cout << "map<int, string>:" << endl;
	for (auto it = mptest.begin(); it != mptest.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void Map_List_Of()
{
	map<int, string> mptest = boost::assign::map_list_of(1, "one") (2, "two");
	cout << "map<int, string>:" << endl;
	for (auto it = mptest.begin(); it != mptest.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}
}

void Repet()
{
	using namespace boost::assign;

	vector<int> vtInt = list_of(1).repeat(3, 2) (3) (4) (5);
	cout << "vector<int>:" << endl;
	for (auto it = vtInt.begin(); it != vtInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	multiset<int> mstInt;
	insert(mstInt).repeat_fun(5, &rand).repeat(2, 1) (10);
	cout << "multiset<int>:" << endl;
	for (auto it = mstInt.begin(); it != mstInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	deque<int> deInt;
	push_front(deInt).range(vtInt.begin(), vtInt.begin() + 5);
	cout << "deque<int>:" << endl;
	for (auto it = deInt.begin(); it != deInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void adapter()
{
	using namespace boost::assign;

	stack<int> skInt = (list_of(1), 2, 3).to_adapter();
	cout << "stack<int>:" << endl;
	while (!skInt.empty())
	{
		cout << skInt.top() << " ";
		skInt.pop();
	}
	cout << endl;

	queue<string> qeStr = (list_of("china"), "us", "uk").repeat(2, "russia").to_adapter();
	cout << "queue<string>:" << endl;
	while (!qeStr.empty())
	{
		cout << qeStr.front() << " ";
		qeStr.pop();
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	/*cout << "AddAndEqual start" << endl;
	AddAndEqual();
	cout << "AddAndEqual end" << endl;

	cout << "parenthesis start" << endl;
	parenthesis();
	cout << "parenthesis end" << endl;*/

	//cout << "list_of start" << endl;
	//List_Of();
	//cout << "list_of end" << endl;

	/*cout << "map_list_of start" << endl;
	Map_List_Of();
	cout << "map_list_of end" << endl;*/

	/*cout << "repet start" << endl;
	Repet();
	cout << "repet end" << endl;*/

	cout << "adapter start" << endl;
	adapter();
	cout << "adapter end" << endl;

	getchar();

	return 0;
}