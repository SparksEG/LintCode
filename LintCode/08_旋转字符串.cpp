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

/*-------------------�ܽ�-----------------------*/
//		����Ŀ��ûʲô���ܽ�ģ���ע��ϸ�ڰɣ���ȡһ�ι���