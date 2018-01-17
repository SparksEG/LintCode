#include <iostream>
#include <vector>
using namespace std;


vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
{
	// write your code here
	vector<int> C;
	auto i = A.begin();
	auto j = B.begin();
	while(i != A.end() && j != B.end())
	{
		if (*i < *j)
		{
			C.push_back(*i);
			i++;
		}
		else
		{
			C.push_back(*j);
			j++;
		}
	}
	while (i != A.end())
	{
		C.push_back(*i);
		i++;
	}
	while (j != B.end())
	{
		C.push_back(*j);
		j++;
	}
	return C;
}

int main()
{
//	vector<int> A{ 1,2,3,7,8,9,16,28,35 };
//	vector<int> B{ 1,2,3,3,3,3,5,6,7,22,46,50 };
	vector<int> A{ 1 };
	vector<int> B{ 1 };
	vector<int> C = mergeSortedArray(A, B);
	for (auto i : C)
		cout << i << endl;
	system("pause");
} 



/*--------------------总结---------------------*/
//		简单题目，防细节错。
//		EG：第一次想将 i（OR j）未移动到尾部 和 已经移动到尾部 的两种情况写在一起，出错（数组溢出）。