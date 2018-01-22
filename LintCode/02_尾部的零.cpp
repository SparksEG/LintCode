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


//----------------------�ܽ�----------------------------*/
//		�Լ���˼·��
//		��10 = 25; ���α��� i(0��...��n)��ͳ��2���ֵĴ�����5���ֵĴ�����ȡ��󣬼�Ϊ�𰸡�
//		�Ľ���5���ֵĴ����϶�С��2���ֵĴ�����
//		ȱ�㣺ʱ�临�ӶȲ�����Ҫ��nlogn��
//
//		���˸��õ�˼·��
//		����5���ֵĴ�����������n = 127��
//		��5, 10, 15, 20, 25, 30, 35, 40��...��������5��(�ܱ�5�����ĸ���m)
//		��25, 50, 75, 100, 125��������5 * 5�����ܱ�25�����ĸ���n��
//		��125������5 * 5 * 5�� ���ܱ�125�����ĸ���l��
//		num = m + n + l;