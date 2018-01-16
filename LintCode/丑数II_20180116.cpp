#include <iostream>
#include <cmath>
using namespace std;

int min(int a, int b)
{
	return 	(a < b ? a : b);
}

int nthUglyNumber(int n)
{
	int *ugly = new int[n];
	int index2, index3, index5, count;
	int maxugly = ugly[0] = 1;
	index2 = index3 = index5 = count = 0;

	while (count < n-1)
	{
		
		maxugly = min(ugly[index2] * 2, min(ugly[index3] * 3, ugly[index5] * 5));
		ugly[++count] = maxugly;

		while (ugly[index2]*2 <= maxugly)
			index2++;
		while (ugly[index3]*3 <= maxugly)
			index3++;
		while (ugly[index5]*5 <= maxugly)
			index5++;
	}
	return ugly[n-1];
}

int main()
{
	cout << nthUglyNumber(9) << endl;
	system("pause");
}


/*--------------------总结--------------------*/
//		利用下一个丑数是由前面的丑数*2（*3 OR *5）得到的
//		设立3个数组存储（其实是使用了ugly本身的存储来代替）*2（*3 OR *5）后
//		来求最小确定下一个丑数是多少

//		自己并没有写出来，原因是：
//		没有想到设立三个数组，而是想通过前一个（或前几个）丑数寻找下一个丑数，却没有找到规律。