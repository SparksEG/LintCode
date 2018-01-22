#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


//vector<string> fizzBuzz(int n) 
//{
//	vector<string> ans;
//	for (int i = 1; i != n + 1; ++i) {
//		string s;
//		if (i % 3 == 0)         s += "Fizz";
//		if (i % 5 == 0)         s += "Buzz";
//		if (s.length() == 0)    s += to_string(i);
//		ans.push_back(s);
//	}
//	return ans;
//}


vector<string> fizzBuzz(int n)
{
	// write your code here
	vector<string> FizzBuzz;
	for (int i = 1; i < n + 1; i++)
	{
		stringstream ss;
		string str;
		ss << i;
		ss >> str;
		if (i % 3 == 0)
		{
			if (i % 5 == 0)
			{
				FizzBuzz.push_back("fizz buzz");
			}
			else
				FizzBuzz.push_back("fizz");
		}
		else
		{
			if (i % 5 == 0)
				FizzBuzz.push_back("buzz");
			else
				FizzBuzz.push_back(str);
		}
	}
	return FizzBuzz;
}

int main()
{
	vector<string>FizzBuzz = fizzBuzz(15);
	for(auto i:FizzBuzz)
		cout << i << endl;
	system("pause");
}


/*-------------------�ܽ�----------------------*/

//		�����⡣
//		�ؼ����� int to string �� string to int��
//		����һ��#include<sstream> + stringstream ʵ�֡�
//		��������to_string(i)ʵ�֡�