#include <iostream>
#include "boost/progress.hpp"
#include <vector>
#include <windows.h>

using namespace std;
using namespace boost;

int main(int argc, char *argv[])
{
	vector<int> vtNum(10, 9);
	boost::progress_display pd(vtNum.size());

	for (int i = 0 ; i < vtNum.size(); ++i)
	{
		cout << i << endl;
		pd.restart(vtNum.size());
		pd += (i + 1);
		Sleep(2000);
	}

	return 0;
}