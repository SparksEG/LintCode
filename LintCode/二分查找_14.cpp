#include <iostream>
#include <vector>
using namespace std;


// answer from net
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int left = 0, right = array.size() - 1;
//	int mid = (left + right) / 2;
//	while (left < right) {
//		if (array[mid] < target) left = mid + 1;
//		if (array[mid] >= target) right = mid;
//		mid = (left + right) / 2;
//	}
//	return array[mid] == target ? mid : -1;
//}

int binarySearch(vector<int> &array, int target)
{
	// write your code here
	int sz = array.size();
	if (sz == 0)
		return -1;
	if (sz == 1)
		return array[0] == target ? 0 : -1;
	int a = 0;
	int b = sz - 1;
	int cur = -1;//!��¼��ǰ����target����λ��

	for (;;)
	{
		int center = (a + b) / 2;
		if (array[a] < target && array[b] > target && a - b == -1)
			return cur;
		if (a - b == -1)
		{
			if (array[a] < target && array[b] > target)
				return cur;
			if (array[a] == target)
			{
				cur = a;
//				while (array[--a] == target) {}
//				return a + 1;
			}
			//while (array[a--] == target) {}
			//return a+1;
			if (array[b] == target)
			{
				cur = b;
//				while (array[--b] == target) {}
//				return b + 1;
			}
			return cur;
		}
		if (array[center] == target)
		{
//			while (array[--center] == target) {}
//			return center + 1;
			cur = center;
			b = center;
		}
		if (array[center] < target)
			a = center;
		else //if (array[center] > target)
			b = center;
	}
	return cur;
}


int main()
{
	vector<int> array{};
	cout << binarySearch(array, 4) << endl;
	system("pause");
}


/*---------------------�ܽ�-----------------------*/
//		�򵥵���Ŀ��Ҫ�󣨵�һ�γ��ֵ�λ�ã�û�п�������������
//		�Ķ���3�Σ����������ܶ�ʱ����for��while��if�ĵ���ʹ�ò���ϸ�������⡣

//		����ע�⵽logn��ʱ��Ҫ���޸�ԭ���ĳ���ע�ͣ�����ʵԭ���ĳ���Ҳ�Ǵ�ģ����ڷ���������ۡ�
//		�����㡰logn��+����һ�γ��ֵ�λ�á����»�˼·�޸ĳ��򣬵�����....ѧϰ�ˡ�
//		��Ҫ���������ӱ���cur��¼����target����λ�á�

//		���Ǵ���ĺü򵥰���Ű�������ǣ�����Ϊ���Ǵ�ģ��������ԡ���
