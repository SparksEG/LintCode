#include <iostream>
using namespace std;

//#define myself

#ifdef myself
int digitCounts(int k, int n)
{
	// write your code here
	int i, index, tempn = n;			//index��λ��			
	for (index = 0; pow(10, index) < n; index++)
		;

	int num = 0; 
	int numten = 0;

	int *a = new int[index];
	for (i = 0; i < index; i++)
	{
		a[i] = tempn % 10;
		tempn = (tempn - a[i]) / 10;
	}

	//����10�ı����ڳ��ֵĴ���
	for (i = 0; i < index; i++)
	//	if (i < index - 1)
	{


		//���������ڳ��ֵĴ���
		if (a[i] >= k)
			num = (a[i]) * numten + num + pow(10, i);
		else
			num = (a[i]) * numten + num;

		numten = numten * 10 + pow(10, i);

		cout << "numten:" << numten << endl;
		cout << "num:" << num << endl;
	}

	//for (i = 0; i < index; i++)
	//	cout << a[i] << endl;


	return 1;
}


/*------------------------�ܽ�----------------------*/
//			�Լ���˼·��
//			��һ����ͨ����λ����λ����λͳ�ƣ�����ó�0-9,0-99,0-999���˹����зƲ�������˼�룬������ţ�+*��
//			�ڶ�������һ����*��λ+���

//			���⣺��k=0ʱ�����ںܶ����⡣������n=15��k=1ʱ��Ҳ�������⣨�����׽������
//				  ���Ƕ�ͳ�ƣ���Ҫ��ȥ���֡�

//			���˵�˼·��
//			��λͳ�Ƹ�Ϊ����k�Ĵ�������3�������
//			��ĳһλ������С��kʱ����ô��λ����i�Ĵ���Ϊ������λ����x��ǰλ��
//			��ĳһλ�����ֵ���kʱ����ô��λ����i�Ĵ���Ϊ������λ����x��ǰλ�� + ��λ���� + 1
//			��ĳһλ�����ִ���kʱ����ô��λ����i�Ĵ���Ϊ��(����λ���� + 1)x��ǰλ��



#else
int digitCounts(int k, int n)
{
	if (n == 0 && k == 0)
		return 1; // �������
	int temp = n, cnt = 0, pow = 1;//pow����ǰλ�ĺ����λ�Ƕ��٣�1Ϊ��λ��10Ϊʮλ��100λǧλ
	while (temp != 0) {
		int digit = temp % 10; // ���ݵ�ǰλ������k�Ĵ�С��ϵ�����������ǰλ�ó��ֹ�k�Ĵ���
		if (digit < k)
			cnt += (temp / 10) * pow;
		else if (digit == k)
			cnt += (temp / 10) * pow + (n - temp * pow + 1);
		else {
			if (!(k == 0 && temp / 10 == 0)) // �ų�û�и���λʱ��Ѱ�ҵ���Ϊ0�����
				cnt += (temp / 10 + 1) * pow;
		}
		temp /= 10;
		pow *= 10;
	}
	return cnt;
}

#endif // !myself

int main()
{
	int k = 4;
	int n = 13;
	cout << digitCounts(k, n) << endl;
	system("pause");
}