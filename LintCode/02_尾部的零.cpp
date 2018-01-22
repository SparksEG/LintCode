#include <iostream>
using namespace std;

//#define myself

//	* @param n: A long integer
//	* @return: An integer, denote the number of trailing zeros in n!

#ifdef myself
long long trailingZeros(long long n)
{
	// write your code here, try to do it without arithmetic operators.
	int numa, numb;
	numa = numb = 0;
	int temp;
	for (int i = 1; i < n + 1; i++)
	{
		temp = i;		
		while (temp % 2 == 0)
		{
			temp = temp / 2;
			numa += 1;
		}
		while (temp % 5 == 0)
		{
			temp = temp / 5;
			numb += 1;
		}
	}

	if (numa < numb)
		return numa;
	else
		return numb;
}
#else 
long long trailingZeros(long long n)
{
	long count = 0;
	for (int i = 1; pow(5, i) <= n; i++)
		count += n / (long)pow(5, i);
	return count;
}

#endif




int main()
{
	long long n = 127;
	
	cout << trailingZeros(n) << endl;
	system("pause");
}


//----------------------总结----------------------------*/
//		自己的思路：
//		将10 = 25; 依次遍历 i(0，...，n)，统计2出现的次数和5出现的次数，取最大，即为答案。
//		改进：5出现的次数肯定小于2出现的次数。
//		缺点：时间复杂度不符合要求（nlogn）
//
//		别人更好的思路：
//		考虑5出现的次数，举例：n = 127。
//		如5, 10, 15, 20, 25, 30, 35, 40，...，有因子5；(能被5整除的个数m)
//		如25, 50, 75, 100, 125，有因子5 * 5；（能被25整除的个数n）
//		如125有因子5 * 5 * 5； （能被125整出的个数l）
//		num = m + n + l;