#include <iostream>
#include <vector>
using namespace std;


// answer from net
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int left = 0, right = array.size() - 1;
//	int mid = (left + right) / 2;
//	while (left < right) {
//		if (array[mid] < target) left = mid + 1;
//		if (array[mid] >= target) right = mid;
//		mid = (left + right) / 2;
//	}
//	return array[mid] == target ? mid : -1;
//}

int binarySearch(vector<int> &array, int target)
{
	// write your code here
	int sz = array.size();
	if (sz == 0)
		return -1;
	if (sz == 1)
		return array[0] == target ? 0 : -1;
	int a = 0;
	int b = sz - 1;
	int cur = -1;//!记录当前最左target出现位置

	for (;;)
	{
		int center = (a + b) / 2;
		if (array[a] < target && array[b] > target && a - b == -1)
			return cur;
		if (a - b == -1)
		{
			if (array[a] < target && array[b] > target)
				return cur;
			if (array[a] == target)
			{
				cur = a;
//				while (array[--a] == target) {}
//				return a + 1;
			}
			//while (array[a--] == target) {}
			//return a+1;
			if (array[b] == target)
			{
				cur = b;
//				while (array[--b] == target) {}
//				return b + 1;
			}
			return cur;
		}
		if (array[center] == target)
		{
//			while (array[--center] == target) {}
//			return center + 1;
			cur = center;
			b = center;
		}
		if (array[center] < target)
			a = center;
		else //if (array[center] > target)
			b = center;
	}
	return cur;
}


int main()
{
	vector<int> array{};
	cout << binarySearch(array, 4) << endl;
	system("pause");
}


/*---------------------总结-----------------------*/
//		简单的题目。要求（第一次出现的位置）没有看清楚，程序错误。
//		改动了3次，当情况种类很多时，对for，while，if的叠加使用不仔细，有问题。

//		后面注意到logn的时间要求，修改原来的程序（注释），其实原本的程序也是错的，存在分情况的讨论。
//		以满足“logn“+“第一次出现的位置”重新换思路修改程序，调好了....学习了。
//		重要点在于增加变量cur记录最左target出现位置。

//		可是答案真的好简单啊，虐。。但是！数组为空是错的！其他都对。。
