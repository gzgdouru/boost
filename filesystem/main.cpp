#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
using namespace boost;

// 路径表示
void test1()
{
	filesystem::path p("/");
	p /= "ect";
	string szFileName = "xinetd.conf";
	p.append(szFileName.begin(), szFileName.end());
	cout << p << endl;

	cout << filesystem::system_complete(p) << endl;
}

// 路径处理
void test2()
{
	filesystem::path p("/usr/local/include/xxx.hpp");
	cout << p.string() << endl;
	//cout << p.directory_string()<< endl;
	cout << p.parent_path() << endl;	// 父路径(不带文件名)
	cout << p.stem() << endl;	// 文件名(不带后缀)
	cout << p.filename() << endl;	// 文件名
	cout << p.extension() << endl;	// 后缀
	cout << "-----------------------------" << endl;

	cout << p.root_name() << endl;
	cout << p.root_directory() << endl;
	cout << p.root_path() << endl;
	cout << "-----------------------------" << endl;

	cout << p.replace_extension() << endl;
	cout << p.replace_extension("hxx") << endl;	// 替换后缀
	cout << p.remove_filename() << endl;	// 删除文件名

	for (auto pos : p)
	{
		cout << "[" << pos << "] ";
	}
	cout << endl;
}

// 文件状态
void test3()
{
	filesystem::path p = "F:\\boost_test";
	cout << filesystem::is_directory(p) << endl;

	p /= "url.txt";
	cout << filesystem::is_regular_file(p) << endl;
}

// 文件属性
#include <time.h>
void test4()
{
	cout << filesystem::initial_path() << endl;
	cout << filesystem::current_path() << endl;

	filesystem::path p("F:\\boost_test\\url.txt");
	cout << filesystem::file_size(p) << endl;

	time_t t = filesystem::last_write_time(p);
	last_write_time(p, time(0));
}

// 文件操作
void test5()
{
	filesystem::path p = "f:\\test";
	if (filesystem::exists(p))
	{
		if (filesystem::is_empty(p))	// remove只能删除空目录
		{
			filesystem::remove(p);
		}
		else
		{
			filesystem::remove_all(p);	// 递归删除
		}
	}

	filesystem::create_directory(p);
	filesystem::copy_file("F:\\boost_test\\url.txt", p /"a.txt");
	cout << "a.txt size:" << filesystem::file_size(p/"a.txt") << endl;

	filesystem::rename(p /"a.txt", p /"b.txt");
	cout << "b.txt size:" << filesystem::file_size(p / "b.txt") << endl;

	//创建多级目录
	filesystem::create_directories(p / "sub_dir" / "sub_dir");
}

// 遍历目录(单次)
void test6()
{
	filesystem::path p("E:/aarch64-linux-android-4.9");
	filesystem::directory_iterator pos(p), end;
	for (; pos != end; ++pos)
	{
		if (filesystem::is_directory(*pos))
		{
			cout << "[" << *pos << "]" << endl;
		}
		else
		{
			cout << "--------->" << *pos << endl;
		}
	}
}

// 遍历目录(递归)
void test7()
{
	filesystem::path p("F:\\boost_test");
	filesystem::recursive_directory_iterator end;
	for (filesystem::recursive_directory_iterator pos(p); pos != end; ++pos)
	{
		if (filesystem::is_directory(*pos))
		{
			cout << "level:" << pos.level() << "-[" << *pos << "]" << endl;
		}
		else
		{
			cout << "level:" << pos.level() << "------->" << *pos << endl;
		}
	}
}

// 遍历目录(单次)
void test8()
{
	filesystem::path p("F:\\boost_test");
	filesystem::recursive_directory_iterator end;
	for (filesystem::recursive_directory_iterator pos(p); pos != end; ++pos)
	{
		if (filesystem::is_directory(*pos))
		{
			pos.no_push();
		}
		cout << *pos << endl;
	}
}

// 文件查找(不支持模糊查找)
string find_file(const filesystem::path& dir, const string &szFile)
{
	if (!filesystem::exists(dir) || !filesystem::is_directory(dir))
	{
		return NULL;
	}

	filesystem::recursive_directory_iterator end;
	for (filesystem::recursive_directory_iterator pos(dir); pos != end; ++pos)
	{
		if (!filesystem::is_directory(*pos) && pos->path().filename() == szFile)
		{
			return pos->path().string();
		}
	}
	return NULL;
}

//文件查找(支持*号模糊匹配)
#include <regex>
#include <boost/algorithm/string.hpp>
void find_files(const filesystem::path &dir, const string &szfileName, vector<string> &vtResult)
{
	string szStr = replace_all_copy(szfileName, ".", "\\.");
	replace_all(szStr, "*", ".*");
	cout << szStr << endl;

	if (!filesystem::exists(dir) || !filesystem::is_directory(dir))
	{
		return;
	}

	filesystem::recursive_directory_iterator end;
	for (filesystem::recursive_directory_iterator pos(dir); pos != end; ++pos)
	{
		string szTmp = pos->path().filename().string();
		if (!filesystem::is_directory(pos->path()) && std::regex_match(szTmp, std::regex(szStr)))
		{
			vtResult.push_back(pos->path().string());
		}
	}
}

int main(int argc, char *argv[])
{
	test1();
	//string szRes = find_file("F:\\", "MutatingAlgo.hpp");
	//cout << szRes << endl;

	/*vector<string> vtRes;
	filesystem::path p("F:\\Boost");
	find_files(p, "*.lib", vtRes);
	copy(vtRes.begin(), vtRes.end(), ostream_iterator<string>(cout, "\n"));*/

	return 0;
}