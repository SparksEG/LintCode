#include <iostream>
#include <vector>
using namespace std;

/*------------------始终二分法------------------*/
/*-----------answer from net good one----------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int left = 0, right = array.size() - 1;
//	int mid = (left + right) / 2;
//	while (left < right) 
//	{
//		if (array[mid] < target) left = mid + 1;
//		if (array[mid] >= target) right = mid;
//		mid = (left + right) / 2;
//	}
//	return array[mid] == target ? mid : -1;
//}

int binarySearch(vector<int> &array, int target)
{
	// write your code here
	int left = 0, right = array.size() - 1;
	int mid = (left + right) / 2;

	while (left < right)						//	因为循环体内有>=，所以成立条件不能有==，否则会无限循环
	{											
		if (array[mid] < target) left = mid + 1;
		if (array[mid] >= target) right = mid;  //	>=的等于是始终保持有array[mid]==target
		mid = (left + right) / 2;				//	将该句放在循环体首部会有left==right!=mid的情况发生；也可以将该句放在循环体首部，循环体外再加上该句。
	}
	return array[mid] == target ? mid : -1;
}

/*------------------始终二分法------------------*/
/*------------answer from me quick one----------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//	int cur = -1;//!记录当前最左target出现位置
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return cur;
//		if (a - b == -1)
//		{
//			if (array[a] < target && array[b] > target)
//				return cur;
//			if (array[a] == target)
//				cur = a;
//			if (array[b] == target)
//				cur = b;
//			return cur;
//		}
//		if (array[center] == target)
//		{
//			cur = center;
//			b = center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//	return cur;
//}

/*---------思路：找到target，回找最前面---------*/
/*-----answer from me slow one,first vision-----*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return -1;
//		if (array[center] == target)
//		{
//			while (array[center] == target && center >= 0)
//			{
//				center--;
//				if (array[center] == target)
//					; 
//				else
//				{
//					center++;
//					break;
//				}
//			}
//			return center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//}


/*---------思路：找到target，回找最前面---------*/
/*-----------answer from azhen slow one---------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return -1;
//		if (array[center] == target)
//		{
//			for (int j = center; j >= 0; j--)
//			{
//				if (array[j] != target)
//					return j + 1;
//			}
//			return center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//}

int main()
{
	vector<int> array{2, 6, 8, 13, 15, 17, 17, 18, 19, 20};
	cout << binarySearch(array, 15) << endl;
	system("pause");
}


/*---------------------总结-----------------------*/
//		简单的题目。要求（第一次出现的位置）没有看清楚，程序错误。
//		改动了3次，当情况种类很多时，对for，while，if的叠加使用不仔细，有问题。

//		后面注意到logn的时间要求，修改原来的程序（注释），其实原本的程序也是错的，存在分情况的讨论，修改正确。
//		以满足“logn“+“第一次出现的位置”重新换思路修改程序，作法始终使用二分法。
//		重要点在于增加变量cur记录最左target出现位置。

//		可是答案真的好简单啊，虐。。但是！数组为空是错的！其他都对。。
