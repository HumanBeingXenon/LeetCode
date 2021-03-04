#include <iostream>
#include <vector>
#include <unordered_map>
#include "data_structure.hpp"

using namespace std;

unordered_map<int, int> map; //A map that stores the indices of each number in inorder vector

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder);

int main(int argc, char const *argv[])
{
    vector<int> preorder = {3, 9, 20, 15, 7}, inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree2(preorder, inorder);
    print_tree(root);
    return 0;
}

/* Example: 
    preorder: [3,9,20,15,7]
    inorder:  [9,3,15,20,7]
    [3, 9, 20, 15, 7] -> [9] [20, 15, 7] -> [15] [7]
    [9, 3, 15, 20, 7] -> [9] [15, 20, 7] -> [15] [7]
    
    [  root ] [       left child tree       ] [       right child tree       ]
     preleft   preleft+1  idx-inleft+preleft   idx-inleft+preleft+1  preright
    [       left child tree       ] [  root ] [       right child tree       ]
     inleft                  idx-1    idx      idx+1                  inright
*/

//A naive algorithm, recurse by splitting the preorder and inorder vectors
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.empty() && inorder.empty())
        return nullptr;

    TreeNode *root = new TreeNode(preorder[0]);
    if (preorder.size() == 1)
        return root;

    int idx;
    for (idx = 0; idx < preorder.size(); idx++)
    {
        if (inorder[idx] == preorder[0])
            break;
    }
    vector<int> pre_left(preorder.begin() + 1, preorder.begin() + idx + 1), pre_right(preorder.begin() + idx + 1, preorder.end());
    vector<int> in_left(inorder.begin(), inorder.begin() + idx), in_right(inorder.begin() + idx + 1, inorder.end());
    root->left = buildTree(pre_left, in_left);
    root->right = buildTree(pre_right, in_right);
    return root;
}

TreeNode *build_helper(vector<int> &preorder, int preleft, int preright, int inleft, int inright)
{
    if (preleft > preright || inleft > inright)
        return nullptr;
    int rootval = preorder[preleft];
    TreeNode *root = new TreeNode(rootval);
    int idx = map[rootval];
    root->left = build_helper(preorder, preleft + 1, idx - inleft + preleft, inleft, idx - 1);
    root->right = build_helper(preorder, idx - inleft + preleft + 1, preright, idx + 1, inright);
    return root;
}

//An improved algorithm,recurse by passing boundary indices and a map that stores the numbers' indices in inorder vector
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
{
    int size = preorder.size();

    for (int i = 0; i < inorder.size(); i++)
        map[inorder[i]] = i;
    
    return build_helper(preorder, 0, size - 1, 0, size - 1);
}