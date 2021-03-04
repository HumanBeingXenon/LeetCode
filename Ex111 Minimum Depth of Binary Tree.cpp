#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

TreeNode *sortedArrayToBST(vector<int> &nums);
TreeNode *sortedArrayToBST(vector<int> &nums, int low, int high);
int minDepth(TreeNode *root);

int main()
{
	vector<int> nums = {1, 2, 3};
	TreeNode *root = sortedArrayToBST(nums);
	print_tree(root);
	cout << minDepth(root) << endl;
	return 0;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
	return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode *sortedArrayToBST(vector<int> &nums, int low, int high)
{
	if (low > high)
		return nullptr;
	else if (low == high)
		return new TreeNode(nums[low]);

	int mid = low + (high - low) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = sortedArrayToBST(nums, low, mid - 1);
	root->right = sortedArrayToBST(nums, mid + 1, high);
	return root;
}

int minDepth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	else if (root->left && root->right == nullptr)
		return 1 + minDepth(root->left);
	else if (root->left == nullptr && root->right)
		return 1 + minDepth(root->right);
	else
		return min(minDepth(root->left), minDepth(root->right)) + 1;
}
