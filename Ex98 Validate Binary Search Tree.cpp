#include <iostream>
#include <vector>
#include <stack>
#include <cfloat>
#include "data_structure.hpp"

using namespace std;

bool isValidBST(TreeNode *root);
bool isValidBST2(TreeNode *root);

int main()
{
	int arr[] = {10, 7, 13, 4, 9, 11, 17, null, null, null, null, null, 12, null, 20}, arr2[] = {INT_MIN};
	TreeNode *root = init_tree(arr, sizeof(arr) / sizeof(int));
	TreeNode *root2 = init_tree(arr2, sizeof(arr2) / sizeof(int));
	print_tree(root);
	print_tree(root2);
	cout << (isValidBST(root2) ? "true" : "false") << " " << (isValidBST2(root) ? "true" : "false") << endl;
	return 0;
}

bool isValidBST(TreeNode *root)
{
	stack<TreeNode *> stk;
	int prev = -DBL_MAX;
	while (!stk.empty() || root)
	{
		while (root)
		{
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		if (root->val <= prev)
			return false;
		prev = root->val;
		root = root->right;
	}
	return true;
}

bool inorder(TreeNode *root, int &prev)
{
	if (root == nullptr)
		return true;
	if (!inorder(root->left, prev))
		return false;
	if (root->val <= prev)
		return false;
	prev = root->val;
	return inorder(root->right, prev);
}

bool isValidBST2(TreeNode *root)
{
	int prev = INT_MIN;
	return inorder(root, prev);
}
