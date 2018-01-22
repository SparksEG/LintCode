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

/*-----------------总结-------------------*/
//			要求：整数。
//			将A + B运算转换为位运算；
//			从位运算方式求考虑 + ， - ，包括进位；
//			此外，
//			位运算还有交换a, b两数的功能：
//			{
//				c = a ^ b;
//				a = a ^ c;
//				b = b ^ c;
//			}