#include <iostream>
#include <vector>
using namespace std;

//bool searchMatrix(vector<vector<int>> &matrix, int target) 
//{
//	// write your code here
//	if (matrix.empty() == true)
//		return false;
//	if (matrix[0][0] > target)
//		return false;
//	int M = matrix.size();
//	int N = matrix[0].size();
//	int m;
//	int Left, Right;
//
//	Left = 0;	Right = M-1;
//	while (true)
//	{
//		if (matrix[M - 1][0] < target)
//		{
//			m = M - 1; break;
//		}
//		int Center = (Left + Right) / 2;
//
//		if (matrix[Center][0] == target)
//			return true;
//		if (matrix[Center][0] < target)
//			Left = Center + 1;
//		if (matrix[Center][0] > target)
//			Right = Center;
//
//
//		if (Left == Right)
//		{
//			if (matrix[Left][0] == target)
//			{
//				m = Left; break;
//			}
//			else
//			{
//				m = Left - 1; break;
//			}
//		}
//	}
//
//	Left = 0;	Right = N-1;
//	while (true)
//	{
//		int Center = (Left + Right) / 2;
//
//		if (matrix[m][Center] == target)
//			return true;
//		if (matrix[m][Center] < target)
//			Left = Center + 1;
//		if (matrix[m][Center] > target)
//			Right = Center;
//
//		if (Left == Right)
//		{
//			if (matrix[m][Left] == target)
//				return true;
//			else
//				return false;
//		}
//	}
//}

//answer from net
bool searchMatrix(vector<vector<int> > &matrix, int target)
{
	// write your code here
	if (matrix.empty() == true)
		return false;
	int low, high, mid = 0;
	low = 0;
	high = matrix.size() - 1;

	while (low <= high) 
	{
		mid = low + (high - low) / 2;
		if (matrix[mid][0] == target) 
			return true;
		else if (matrix[mid][0] > target)
			high = mid - 1;
		else 
			low = mid + 1;
	}

	// make sure the row starts with a number less than the target targetent
	if (matrix[mid][0] > target)
		mid--;
	int row = mid;

	// binary search the column number
	low = 0;
	high = matrix[0].size() - 1;
	while (low <= high) 
	{
		mid = low + (high - low) / 2;
		if (matrix[row][mid] == target) 
			return true;
		else if (matrix[row][mid] > target) 
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return false;
}

int main()
{
	vector<vector<int>> matrix;
	matrix.resize(3);
	matrix[0].push_back(1);
	matrix[0].push_back(3);
	matrix[0].push_back(5);
	matrix[0].push_back(7);
	matrix[1].push_back(10);
	matrix[1].push_back(11);
	matrix[1].push_back(16);
	matrix[1].push_back(20);
	matrix[2].push_back(23);
	matrix[2].push_back(30);
	matrix[2].push_back(34);
	matrix[2].push_back(50);

	if (searchMatrix(matrix, 7))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
}

/*-------------------总结-------------------*/
/*自己考虑问题解法不够统一，往往是拆分多种情况，容易错误且问题理解不够深刻。*/
