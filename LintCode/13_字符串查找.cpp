#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(const char *source, const char *target)
{
	if (source == NULL || target == NULL)
		return -1;
	if (*source == '\0' && *target == '\0')
		return 0;
	if (*target == '\0')
		return 0;
	int lensour = strlen(source);
	int lentar = strlen(target);

	int i = 0;
	int j = 0;
	while (source[i] != '\0')
	{
		while (j<lentar && i<lensour)
		{
			if (source[i] == target[j])
			{
				i++;
				j++;
			}
			else
			{
				if (j != 0)
					i--;
				i++;
				j = 0;
			}
		}
		if(j==lentar)
			return (i - j);
	}
	return -1;
}


//int strStr(const char *source, const char *target) {
//	// write your code here
//	if (source == NULL || target == NULL)
//		return -1;
//	if (target[0] == '\0')
//		return 0;
//	int start = 0;
//	while (source[start] != '\0') {
//		int t = 0;
//		int s = 0;
//		while (source[start + s] != '\0' && target[t] != '\0' && source[start + s] == target[t]) {
//			s++;
//			t++;
//		}
//		if (target[t] == '\0')
//			return start;
//		start++;
//	}
//	return -1;
//}

int main()
{
	char target[] = { "bc" };
	char source[] = { "abcdabcdefg" };
	cout << strStr(source, target) << endl;
	system("pause");
}




/*--------------------总结--------------------*/
//		简单的题目。大公司也会考基础。
//		自己做的结果并不好，反复修改了5次才通过。
//		原因是情况种类多，事先没有拟好程序思路，上来就写，结果是 出错->Debug->出错->Debug->出错...

//		以后应该全力避免这种情况，没有成熟的思路不要轻易动笔，否则只能是“缝缝补补”的瓦匠工。


//		自己的方法唯一的优点在于当target和source前面有部分重复时，
//		答案是用了两个临时游标去判断，需要撤回到重复部分最前端。
//		自己是用了两个游标一直去判断，只需要撤回到最新开始的地方，少比较了j-1次，但多种情况要自己考虑清楚！