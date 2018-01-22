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


/*--------------------�ܽ�--------------------*/
//		������һ����������ǰ��ĳ���*2��*3 OR *5���õ���
//		����3������洢����ʵ��ʹ����ugly����Ĵ洢�����棩*2��*3 OR *5����
//		������Сȷ����һ�������Ƕ���

//		�Լ���û��д������ԭ���ǣ�
//		û���뵽�����������飬������ͨ��ǰһ������ǰ����������Ѱ����һ��������ȴû���ҵ����ɡ�