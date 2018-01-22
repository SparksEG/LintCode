#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
	return 	(a < b ? b : a);
}

int min(int a, int b)
{
	return 	(a < b ? a : b);
}

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Median3(vector<int> &nums, int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (nums[Left] > nums[Center])
		Swap(nums[Left], nums[Center]);
	if (nums[Left] > nums[Right])
		Swap(nums[Left], nums[Right]);
	if (nums[Center] > nums[Right])
		Swap(nums[Center], nums[Right]);

	Swap(nums[Center], nums[Right - 1]);
	return nums[Right - 1];
}

int kthLargestElementHelper(int k, vector<int> &nums, int Left, int Right)
{
	if (Right - Left + 1 > 2)
	{
		int Pivot = Median3(nums, Left, Right);
		int i = Left;	int j = Right - 1;
		for (;;)
		{
			while (nums[++i] < Pivot);//重点
			while (nums[--j] > Pivot);//重点
			if (i < j)
				Swap(nums[i], nums[j]);
			else
				break;
		}
		Swap(nums[i], nums[Right - 1]);

		if (k < i)
			return kthLargestElementHelper(k, nums, Left, i - 1);
		else if (k == i)
			return nums[i];
		else//if (k > i)
			return kthLargestElementHelper(k /*- (i - Left) - 1*/, nums, i + 1, Right);
	}
	//要注意快排（分）只能解决数组size>=3的情况
	else
	{
		if (nums[Left] > nums[Right])
			Swap(nums[Left], nums[Right]);
		return nums[k];
	}
}

int kthLargestElement(int k, vector<int> &nums)
{
	if (k > nums.size())
		return -1;
	k--;
	return kthLargestElementHelper(k, nums, 0, nums.size()-1);
}


int main()
{
	vector<int> nums(10, 1);
	for (int j = 0; j < nums.size(); j++)
		nums[j] = (j - 6)*(j - 5);
	cout << kthLargestElement(4, nums) << endl << endl;

	for (auto i : nums)
		cout << i << endl;


	system("pause");
}


/*-------------------总结----------------------*/
//		快速排序的微改：快速选择。
//		参考书《数据结构与算法分析》。
//		重点1：标注。考虑到Pivot=A[i]=A[j]的情况。
//		重点2：快排（选）方法只能用于N>=3的情况。

