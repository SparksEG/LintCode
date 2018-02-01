#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};

//�ݹ�ǰ����� 
void inorderTraversalHelper(vector<int> &TreeOrder, TreeNode* cur)     //�ݹ�ǰ����� 
{
	if (cur != NULL)
	{
		inorderTraversalHelper(TreeOrder, cur->left);
		TreeOrder.push_back(cur->val);
		inorderTraversalHelper(TreeOrder, cur->right);
	}
}

vector<int> inorderTraversal(TreeNode * root)
{
	// write your code here
	vector<int> TreeOrder;
	inorderTraversalHelper(TreeOrder, root);
	return TreeOrder;
}

//�ǵݹ�������� from OJ.net
vector<int> inorderTraversal(TreeNode *root) 
{
	// write your code here
	stack<TreeNode*> stk;
	vector<int> res;
	stk.push(root);
	while (!stk.empty()) 
	{
		TreeNode* t = stk.top();
		stk.pop();
		if (t) 
		{
			stk.push(t->right);
			stk.push(t);
			stk.push(t->left);
		}
		else if (!stk.empty()) 
		{
			res.push_back(stk.top()->val);
			stk.pop();
		}
	}
	return res;
}

/*
* �ܽ᣺
* �ǵݹ��������ʹ����stack���ݽṹ
* �ؼ����裺ȥcur����cur->right��cur��cur->left����˳��
* �ؼ���⣺stk.push(element)��elementǰ����NULL��
*/


//�ǵݹ�������� from ӡ��ʼ�   (����üǺ����)
vector<int> inorderTraversal(TreeNode *root) {
	vector<int> inTreeOrder;
	stack<TreeNode*> stk;
	TreeNode* p = root;
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		if (!stk.empty()) {
			p = stk.top();
			inTreeOrder.push_back(p->val);
			stk.pop();
			p = p->right;
		}
	}
	return inTreeOrder;
}

