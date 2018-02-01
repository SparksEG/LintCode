#include <iostream>
#include <vector>
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

//�ݹ�ǰ����� 
void preorderTraversalHelper(vector<int> &TreeOrder,TreeNode* cur)     
{
	if (cur != NULL)
	{
		TreeOrder.push_back(cur->val);
		preorderTraversalHelper(TreeOrder, cur->left);
		preorderTraversalHelper(TreeOrder, cur->right);
	}
}

vector<int> preorderTraversal(TreeNode * root) 
{
	// write your code here
	vector<int> TreeOrder;
	preorderTraversalHelper(TreeOrder, root);
	return TreeOrder;
}

//�ǵݹ�ǰ����� 
vector<int> preorderTraversal(TreeNode *root) {
	// write your code here
	vector<int> res;
	stack<TreeNode*> stk;
	if (root)
		stk.push(root);
	while (!stk.empty())
	{
		TreeNode* t = stk.top();
		stk.pop();
		res.push_back(t->val);
		if (t->right)
			stk.push(t->right);
		if (t->left)
			stk.push(t->left);
	}
	return res;
}


/*
* �ܽ᣺
* �ǵݹ�ǰ�����ʹ����stack���ݽṹ��Ҳ���Բ�ʹ�á�
* ʹ��stackʱ��ע����right��left��
*/