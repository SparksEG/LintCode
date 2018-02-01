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

//递归前序遍历 
void inorderTraversalHelper(vector<int> &TreeOrder, TreeNode* cur)     //递归前序遍历 
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

//非递归中序遍历 from OJ.net
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
* 总结：
* 非递归中序遍历使用了stack数据结构
* 关键步骤：去cur，进cur->right，cur，cur->left（有顺序）
* 关键理解：stk.push(element)的element前必有NULL；
*/


//非递归中序遍历 from 印象笔记   (这个好记好理解)
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

