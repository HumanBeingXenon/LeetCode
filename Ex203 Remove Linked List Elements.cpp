#include <iostream>
#include "data_structure.hpp"

using namespace std;

ListNode *removeElements(ListNode *head, int val);

int main()
{
    vector<int> v = {1, 2, 6, 3, 4, 5, 6};
    vector<int> v2 = {6, 6, 6, 6, 6, 6, 6};
    ListNode *head = init_list(v2);
    print_list(head);
    head = removeElements(head, 6);
    print_list(head);
    return 0;
}

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *dummy_head = new ListNode(0);
    dummy_head->next = head;

    ListNode *prev = dummy_head;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->val == val)
            prev->next = ptr->next;
        else
            prev = ptr;
    }
    return dummy_head->next;
}
