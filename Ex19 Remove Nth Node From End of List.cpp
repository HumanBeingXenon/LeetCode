#include <iostream>
#include "data_structure.hpp"

using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n);

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = init_list(v);
    print_list(head);
    head = removeNthFromEnd(head, 5);
    print_list(head);
    return 0;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy_head = new ListNode(0, head);
    ListNode *fast_ptr = dummy_head, *slow_ptr = dummy_head;
    for (int i = 0; i <= n; i++)
        fast_ptr = fast_ptr->next;
    while (fast_ptr != nullptr)
    {
        fast_ptr = fast_ptr->next;
        slow_ptr = slow_ptr->next;
    }
    ListNode *deleted_node = slow_ptr->next;
    slow_ptr->next = slow_ptr->next->next;
    delete deleted_node;
    return dummy_head->next;
}