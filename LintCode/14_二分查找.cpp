#include <iostream>
#include <vector>
using namespace std;

/*------------------ʼ�ն��ַ�------------------*/
/*-----------answer from net good one----------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int left = 0, right = array.size() - 1;
//	int mid = (left + right) / 2;
//	while (left < right) 
//	{
//		if (array[mid] < target) left = mid + 1;
//		if (array[mid] >= target) right = mid;
//		mid = (left + right) / 2;
//	}
//	return array[mid] == target ? mid : -1;
//}

int binarySearch(vector<int> &array, int target)
{
	// write your code here
	int left = 0, right = array.size() - 1;
	int mid = (left + right) / 2;

	while (left < right)						//	��Ϊѭ��������>=�����Գ�������������==�����������ѭ��
	{											
		if (array[mid] < target) left = mid + 1;
		if (array[mid] >= target) right = mid;  //	>=�ĵ�����ʼ�ձ�����array[mid]==target
		mid = (left + right) / 2;				//	���þ����ѭ�����ײ�����left==right!=mid�����������Ҳ���Խ��þ����ѭ�����ײ���ѭ�������ټ��ϸþ䡣
	}
	return array[mid] == target ? mid : -1;
}

/*------------------ʼ�ն��ַ�------------------*/
/*------------answer from me quick one----------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//	int cur = -1;//!��¼��ǰ����target����λ��
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return cur;
//		if (a - b == -1)
//		{
//			if (array[a] < target && array[b] > target)
//				return cur;
//			if (array[a] == target)
//				cur = a;
//			if (array[b] == target)
//				cur = b;
//			return cur;
//		}
//		if (array[center] == target)
//		{
//			cur = center;
//			b = center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//	return cur;
//}

/*---------˼·���ҵ�target��������ǰ��---------*/
/*-----answer from me slow one,first vision-----*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return -1;
//		if (array[center] == target)
//		{
//			while (array[center] == target && center >= 0)
//			{
//				center--;
//				if (array[center] == target)
//					; 
//				else
//				{
//					center++;
//					break;
//				}
//			}
//			return center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//}


/*---------˼·���ҵ�target��������ǰ��---------*/
/*-----------answer from azhen slow one---------*/
//int binarySearch(vector<int> &array, int target)
//{
//	// write your code here
//	int sz = array.size();
//	if (sz == 0)
//		return -1;
//	if (sz == 1)
//		return array[0] == target ? 0 : -1;
//	int a = 0;
//	int b = sz - 1;
//
//	for (;;)
//	{
//		int center = (a + b) / 2;
//		if (array[a] < target && array[b] > target && a - b == -1)
//			return -1;
//		if (array[center] == target)
//		{
//			for (int j = center; j >= 0; j--)
//			{
//				if (array[j] != target)
//					return j + 1;
//			}
//			return center;
//		}
//		if (array[center] < target)
//			a = center;
//		else //if (array[center] > target)
//			b = center;
//	}
//}

int main()
{
	vector<int> array{2, 6, 8, 13, 15, 17, 17, 18, 19, 20};
	cout << binarySearch(array, 15) << endl;
	system("pause");
}


/*---------------------�ܽ�-----------------------*/
//		�򵥵���Ŀ��Ҫ�󣨵�һ�γ��ֵ�λ�ã�û�п�������������
//		�Ķ���3�Σ����������ܶ�ʱ����for��while��if�ĵ���ʹ�ò���ϸ�������⡣

//		����ע�⵽logn��ʱ��Ҫ���޸�ԭ���ĳ���ע�ͣ�����ʵԭ���ĳ���Ҳ�Ǵ�ģ����ڷ���������ۣ��޸���ȷ��
//		�����㡰logn��+����һ�γ��ֵ�λ�á����»�˼·�޸ĳ�������ʼ��ʹ�ö��ַ���
//		��Ҫ���������ӱ���cur��¼����target����λ�á�

//		���Ǵ���ĺü򵥰���Ű�������ǣ�����Ϊ���Ǵ�ģ��������ԡ���
