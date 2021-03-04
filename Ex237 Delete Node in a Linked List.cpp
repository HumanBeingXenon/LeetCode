#include <iostream>
#include "data_structure.hpp"

using namespace std;

void deleteNode(ListNode *node);

int main(int argc, char const *argv[])
{
    vector<int> v = {4, 5, 1, 9};
    int val = 5;
    ListNode *head = init_list(v);
    print_list(head);
    ListNode *ptr;
    for (ptr = head; ptr != nullptr; ptr = ptr->next)
        if (ptr->val == val)
            break;
    deleteNode(ptr);
    print_list(head);
    return 0;
}

void deleteNode(ListNode *node)
{
    ListNode *temp = node->next;
    node->next = temp->next;
    node->val = temp->val;
    delete temp;
}
