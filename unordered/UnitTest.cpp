#include "../public/headfile.hpp"
#include "boost/unordered_set.hpp"
#include "boost/unordered_map.hpp"
using namespace boost;

template<typename T>
void hash_func(const string &szStr)
{
	cout << szStr << endl;

	T s = { 1, 2, 3, 4, 5 };
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << s.size() << endl;

	s.clear();
	cout << s.empty() << endl;

	s.insert(8);
	s.insert(54);
	cout << s.size() << endl;
	cout << *s.find(8) << endl;

	s.erase(54);
}

void testOne()
{
	hash_func<hash_set<int> >("hash_set:");
	hash_func<unordered_set<int> >("unordered_set:");
}

void testTwo()
{
	cout << "unodered_map:" << endl;
	unordered_map<int, string> umap = { {1, "one"}, {2, "two"}, {3, "three"} };
	umap.insert(make_pair(10, "ten"));
	cout << umap[10] << endl;

	umap[11] = "eleven";
	umap[15] = "fifteen";
	for (auto it = umap.begin(); it != umap.end(); ++it)
	{
		cout << it->first << "-" << it->second << " ";
	}
	cout << endl;

	umap.erase(11);
	cout << umap.size() << endl;

	cout << "hash_map:" << endl;
	hash_map<int, string> hmap = { {4,"four"}, {5,"five"}, {6,"six"} };
	for (auto it = hmap.begin(); it != hmap.end(); ++it)
	{
		cout << it->first << "-" << it->second << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	//testOne();

	testTwo();

	getchar();
	return 0;
}