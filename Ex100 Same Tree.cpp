#include <iostream>
#include <queue>
#include "data_structure.hpp"

using namespace std;

bool check(TreeNode *p, TreeNode *q);
bool isSameTree(TreeNode *p, TreeNode *q);

int main()
{
	int arrP[] = {1, 2, null, 3, 4, 5}, arrQ[] = {1, 2, 3, 4, 5, 6}, arrR[] = {1, 2, null, 3, 4, 5};
	TreeNode *p = init_tree(arrP, sizeof(arrP) / sizeof(int));
	print_tree(p);
	TreeNode *q = init_tree(arrQ, sizeof(arrQ) / sizeof(int));
	print_tree(q);
	TreeNode *r = init_tree(arrR, sizeof(arrR) / sizeof(int));
	print_tree(r);

	cout << (isSameTree(p, q) ? "true" : "false") << " " << (isSameTree(p, r) ? "true" : "false") << endl;
	return 0;
}

bool check(TreeNode *p, TreeNode *q)
{
	if (p == nullptr && q == nullptr)
		return true;
	if (q == nullptr || p == nullptr)
		return false;
	if (p->val != q->val)
		return false;
	return true;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
	queue<TreeNode *> que;
	que.push(p);
	que.push(q);
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		q = que.front();
		que.pop();
		if (!check(p, q))
			return false;
		if (p)
		{
			que.push(p->left);
			que.push(q->left);
			que.push(p->right);
			que.push(q->right);
		}
	}
	return true;
}
