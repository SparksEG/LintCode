#include <iostream>
using namespace std;

//#define myself

#ifdef myself
int digitCounts(int k, int n)
{
	// write your code here
	int i, index, tempn = n;			//index是位数			
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

	//计算10的倍数内出现的次数
	for (i = 0; i < index; i++)
	//	if (i < index - 1)
	{


		//计算余数内出现的次数
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


/*------------------------总结----------------------*/
//			自己的思路：
//			第一步：通过高位到低位的诸位统计，计算得出0-9,0-99,0-999，此过程有菲波那切数思想，运算符号（+*）
//			第二步：第一步的*高位+余项。

//			问题：当k=0时，存在很多问题。且类似n=15，k=1时，也存在问题（问题易解决）。
//				  都是多统计，需要减去部分。

//			别人的思路：
//			按位统计改为出现k的次数，分3种情况：
//			当某一位的数字小于k时，那么该位出现i的次数为：更高位数字x当前位数
//			当某一位的数字等于k时，那么该位出现i的次数为：更高位数字x当前位数 + 低位数字 + 1
//			当某一位的数字大于k时，那么该位出现i的次数为：(更高位数字 + 1)x当前位数



#else
int digitCounts(int k, int n)
{
	if (n == 0 && k == 0)
		return 1; // 特殊情况
	int temp = n, cnt = 0, pow = 1;//pow代表当前位的后面低位是多少，1为个位，10为十位，100位千位
	while (temp != 0) {
		int digit = temp % 10; // 根据当前位置数和k的大小关系，可以算出当前位置出现过k的次数
		if (digit < k)
			cnt += (temp / 10) * pow;
		else if (digit == k)
			cnt += (temp / 10) * pow + (n - temp * pow + 1);
		else {
			if (!(k == 0 && temp / 10 == 0)) // 排除没有更高位时，寻找的数为0的情况
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