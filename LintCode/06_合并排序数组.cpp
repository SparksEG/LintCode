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



/*--------------------�ܽ�---------------------*/
//		����Ŀ����ϸ�ڴ�
//		EG����һ���뽫 i��OR j��δ�ƶ���β�� �� �Ѿ��ƶ���β�� ���������д��һ�𣬳��������������