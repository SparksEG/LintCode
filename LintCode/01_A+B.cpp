#include <iostream>
using namespace std;

/*
* @param a: An integer
* @param b: An integer
* @return: The sum of a and b
*/
int aplusb(int a, int b) {
	// write your code here
	int tempa, tempb;
	while (b != 0)
	{
		tempa = a ^ b;
		tempb = (a&b) << 1;
		a = tempa;
		b = tempb;
	}
	return a;
}

int main()
{
	int a = 27;
	int b = -67;
	int c = a^b;
	b = b ^ c;
	a = a ^ c;
	cout << "a = " << a <<"	,b = " << b << endl;
	system("pause");
}

/*-----------------�ܽ�-------------------*/
//			Ҫ��������
//			��A + B����ת��Ϊλ���㣻
//			��λ���㷽ʽ���� + �� - ��������λ��
//			���⣬
//			λ���㻹�н���a, b�����Ĺ��ܣ�
//			{
//				c = a ^ b;
//				a = a ^ c;
//				b = b ^ c;
//			}