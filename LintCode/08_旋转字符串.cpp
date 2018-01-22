#include <iostream>
#include <vector>
#include <string>
using namespace std;

void rotateString(string &str, int offset) 
{
	// write your code here
	string restr;
	int sz = str.size();

	if (sz == 0)
		return;

	offset = offset % sz;
	offset = sz - offset;
	for (int i = 0; i < sz; i++)
	{
		int k;
		if (i + offset < sz)
			restr.push_back(str[i + offset]);
		else
			restr.push_back(str[i + offset - sz]);
	}
	str = restr;
}

int main()
{
	string str("");
	rotateString(str, 3);
	cout << str << endl;

	system("pause");
}

/*-------------------总结-----------------------*/
//		简单题目，没什么可总结的，多注意细节吧，争取一次过。