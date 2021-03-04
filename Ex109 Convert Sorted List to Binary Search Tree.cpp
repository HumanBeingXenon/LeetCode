#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "data_structure.hpp"

using namespace std;

TreeNode *sortedListToBST(ListNode *head);
TreeNode *sortedListToBST2(ListNode *head);

int main(int argc, char const *argv[])
{
    int arr[] = {-10, -3, 0, 5, 9};
    ListNode *head = init_list(arr, sizeof(arr) / sizeof(int));
    print_list(head);
    TreeNode *root = sortedListToBST2(head);
    print_tree(root);
    return 0;
}

ListNode *find_midnode(ListNode *head)
{
    ListNode *prevptr = nullptr, *slowptr = head, *fastptr = head;
    while (fastptr && fastptr->next)
    {
        prevptr = slowptr;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    if (prevptr)
        prevptr->next = nullptr;
    return slowptr;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *midptr = find_midnode(head);
    TreeNode *root = new TreeNode(midptr->val);
    if (head == midptr)
        return root;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midptr->next);
    return root;
}

vector<ListNode *> convert_linklist_to_vector(ListNode *head)
{
    vector<ListNode *> vector_listnode;
    for (ListNode *ptr = head; ptr; ptr = ptr->next)
        vector_listnode.push_back(ptr);
    return vector_listnode;
}

TreeNode *convert_vector_to_BST(vector<ListNode *> vector_listnode, int low, int high)
{
    if (low > high)
        return nullptr;
    
    int mid = (high + low) / 2;
    TreeNode *root = new TreeNode(vector_listnode[mid]->val);
    
    if (low == high)
        return root;

    root->left = convert_vector_to_BST(vector_listnode, low, mid - 1);
    root->right = convert_vector_to_BST(vector_listnode, mid + 1, high);
    return root;
}

TreeNode *sortedListToBST2(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    vector<ListNode *> vector_listnode = convert_linklist_to_vector(head);
    TreeNode *root = convert_vector_to_BST(vector_listnode, 0, vector_listnode.size() - 1);
    return root;
}