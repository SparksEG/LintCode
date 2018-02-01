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


////�ݹ�������
//void postorderTraversalHelper(vector<int> &TreeOrder, TreeNode* cur)     //�ݹ�ǰ����� 
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


////�ǵݹ������� from OJ.net
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



//�ǵݹ������� from ӡ��ʼ�  (����üǺ����)
/*
* Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ��
* ���P���������Ӻ��Һ��ӣ������ֱ�ӷ�����������P�������ӻ����Һ��ӣ�����
* �����Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣�����������������
* ��P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���
* ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
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