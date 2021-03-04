#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high);
int maxDepth(TreeNode* root);

int main(){
	vector<int> nums = {-10, -3, 0, 5, 9};
	TreeNode *p = sortedArrayToBST(nums);
	print_tree(p);
	cout << maxDepth(p) << endl; 
	return 0;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return sortedArrayToBST(nums, 0, nums.size() - 1);
}

TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high){
	if(low > high) return nullptr;
	else if(low == high) return new TreeNode(nums[low]);
	
	int mid = low + (high - low) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	root->left = sortedArrayToBST(nums, low, mid - 1);
	root->right = sortedArrayToBST(nums, mid + 1, high); 
	return root; 
}

int maxDepth(TreeNode* root) {
	if(root == nullptr) return 0;
	return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
}
