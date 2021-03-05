#include <iostream>
#include <vector>
#include "data_structure.hpp"

int main(int argc, char const *argv[])
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    vector<int> v2 = {1, 2, 3, 4, null, 5, 6, null, 7, null, null, 8, 9, null, null, null, 10, null, 11, null, null, 12};
    vector<vector<int>> v3 = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};

    ListNode *head = init_list(v1, true);
    TreeNode *root = init_tree(v2);
    Node *node = init_graph(v3);

    print_list(head);
    print_tree(root);
    print_bfs(node);

    destroy_list(head, true);
    destroy_tree(root, true);
    destroy_graph(node, true);
    return 0;
}
