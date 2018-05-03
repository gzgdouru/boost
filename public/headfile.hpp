#ifndef _HEAD_FILE_HPP
#define _HEAD_FILE_HPP

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
#include <hash_set>
#include <hash_map>
#include "boost/tuple/tuple.hpp"

using namespace std;
using namespace boost;

template<class T>
void printSTL(const T &target, const string &szStr = "")
{
	if (!szStr.empty())
	{
		cout << szStr << ": ";
	}

	for (auto it = target.begin(); it != target.end(); ++it)
	{
		cout << "[" << *it << "] ";
	}
	cout << endl;
}

template<typename T>
void printMap(const T &target, const string &szStr = "")
{
	if (!szStr.empty())
	{
		cout << szStr << ": " << endl;
	}

	for (auto it = target.begin(); it != target.end(); ++it)
	{
		cout << it->first << "-" << it->second << endl;
	}
}

template<typename Tuple>
void printTuple(const Tuple& t)
{
	cout << t.get_head() << " ";
	printTuple(t.get_tail());
}

void printTuple(const boost::tuples::null_type &)
{
	cout << endl;
}

#endif