#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
using namespace boost;

// ·����ʾ
void test1()
{
	filesystem::path p("/");
	p /= "ect";
	string szFileName = "xinetd.conf";
	p.append(szFileName.begin(), szFileName.end());
	cout << p << endl;

	cout << filesystem::system_complete(p) << endl;
}

// ·������
void test2()
{
	filesystem::path p("/usr/local/include/xxx.hpp");
	cout << p.string() << endl;
	//cout << p.directory_string()<< endl;
	cout << p.parent_path() << endl;	// ��·��(�����ļ���)
	cout << p.stem() << endl;	// �ļ���(������׺)
	cout << p.filename() << endl;	// �ļ���
	cout << p.extension() << endl;	// ��׺
	cout << "-----------------------------" << endl;

	cout << p.root_name() << endl;
	cout << p.root_directory() << endl;
	cout << p.root_path() << endl;
	cout << "-----------------------------" << endl;

	cout << p.replace_extension() << endl;
	cout << p.replace_extension("hxx") << endl;	// �滻��׺
	cout << p.remove_filename() << endl;	// ɾ���ļ���

	for (auto pos : p)
	{
		cout << "[" << pos << "] ";
	}
	cout << endl;
}

// �ļ�״̬
void test3()
{
	filesystem::path p = "F:\\boost_test";
	cout << filesystem::is_directory(p) << endl;

	p /= "url.txt";
	cout << filesystem::is_regular_file(p) << endl;
}

// �ļ�����
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

// �ļ�����
void test5()
{
	filesystem::path p = "f:\\test";
	if (filesystem::exists(p))
	{
		if (filesystem::is_empty(p))	// removeֻ��ɾ����Ŀ¼
		{
			filesystem::remove(p);
		}
		else
		{
			filesystem::remove_all(p);	// �ݹ�ɾ��
		}
	}

	filesystem::create_directory(p);
	filesystem::copy_file("F:\\boost_test\\url.txt", p /"a.txt");
	cout << "a.txt size:" << filesystem::file_size(p/"a.txt") << endl;

	filesystem::rename(p /"a.txt", p /"b.txt");
	cout << "b.txt size:" << filesystem::file_size(p / "b.txt") << endl;

	//�����༶Ŀ¼
	filesystem::create_directories(p / "sub_dir" / "sub_dir");
}

// ����Ŀ¼(����)
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

// ����Ŀ¼(�ݹ�)
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

// ����Ŀ¼(����)
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

// �ļ�����(��֧��ģ������)
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

//�ļ�����(֧��*��ģ��ƥ��)
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