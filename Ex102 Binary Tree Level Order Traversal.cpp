#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "data_structure.hpp"

using namespace std;

void print_vector(vector<vector<int>> v);
vector<vector<int>> levelOrder(TreeNode *root);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    TreeNode *root = init_tree(arr, sizeof(arr) / sizeof(int));
    print_tree(root);
    vector<vector<int>> v = levelOrder(root);
    print_vector(v);
    return 0;
}

void print_vector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (j)
                cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> vector_levelorder; //A vector that stores the level order traversal of its nodes' values
    if (root == nullptr)
        return vector_levelorder;

    vector<TreeNode *> vector_cur; //A vector that stores current level of nodes
    vector_cur.push_back(root);
    while (!vector_cur.empty())
    {
        vector<int> vector_levelval;     //A vector that stores all values of nodes at current level
        vector<TreeNode *> vector_next;  //A vector that stores next level of nodes
        for (TreeNode *ptr : vector_cur) //Traverse current level of nodes in vector_cur
        {
            vector_levelval.push_back(ptr->val);
            //Push nodes of next layer into vector_next
            if (ptr->left != nullptr)
                vector_next.push_back(ptr->left);
            if (ptr->right != nullptr)
                vector_next.push_back(ptr->right);
        }
        vector_levelorder.push_back(vector_levelval); //Add vector_levelval, which all values of nodes at current level, to vector_levelorder
        vector_cur = vector_next;                     //Move forward to next layer of nodes
    }
    return vector_levelorder;
}