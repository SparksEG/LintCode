#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


////递归后序遍历
//void postorderTraversalHelper(vector<int> &TreeOrder, TreeNode* cur)     //递归前序遍历 
//{
//	if (cur != NULL)
//	{
//		postorderTraversalHelper(TreeOrder, cur->left);
//		postorderTraversalHelper(TreeOrder, cur->right);
//		TreeOrder.push_back(cur->val);
//	}
//}
//
//vector<int> postorderTraversal(TreeNode * root)
//{
//	// write your code here
//	vector<int> TreeOrder;
//	postorderTraversalHelper(TreeOrder, root);
//	return TreeOrder;
//}


////非递归后序遍历 from OJ.net
//vector<int> postorderTraversal(TreeNode *root) 
//{
//	// write your code here
//	vector<int> res;
//	stack<TreeNode*> v;
//	stack<TreeNode*> s;
//	if (root) {
//		s.push(root);
//		v.push(NULL);
//	}
//	while (!s.empty()) {
//		TreeNode *t = s.top();
//		if (t == v.top()) {
//			s.pop();
//			v.pop();
//			res.push_back(t->val);
//		}
//		else {
//			if (t->right) {
//				s.push(t->right);
//			}
//			if (t->left) {
//				s.push(t->left);
//			}
//			v.push(t);
//		}
//	}
//	return res;
//}



//非递归后序遍历 from 印象笔记  (这个好记好理解)
/*
* 要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
* 如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是
* 其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，
* 则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子
* 前面被访问，左孩子和右孩子都在根结点前面被访问。
*/

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> postTreeOrder;
	if (root == NULL)
		return postTreeOrder;
	stack<TreeNode*> stk;
	TreeNode* pre = NULL;
	TreeNode* cur = root;
	stk.push(cur);
	while (!stk.empty()) {
		cur = stk.top();
		if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right))) {
			postTreeOrder.push_back(cur->val);
			stk.pop();
			pre = cur;
		}
		else {
			if (cur->right != NULL)
				stk.push(cur->right);
			if (cur->left != NULL)
				stk.push(cur->left);
		}
	}
	return postTreeOrder;
}