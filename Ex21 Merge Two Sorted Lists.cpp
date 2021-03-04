#include <iostream>
#include "data_structure.hpp"

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2);

int main(int argc, char const *argv[])
{
    vector<int> v1 = {-9, 3}, v2 = {5, 7};
    ListNode *l1 = init_list(v1);
    ListNode *l2 = init_list(v2);
    ListNode *l3 = mergeTwoLists(l1, l2);
    print_list(l3);
    return 0;
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0), *ptr = head, *ptr1, *ptr2;
    for (ptr1 = l1, ptr2 = l2; ptr1 != nullptr && ptr2 != nullptr;)
    {
        if (ptr1->val <= ptr2->val)
        {
            ptr->next = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
        }
        else
        {
            ptr->next = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    if (ptr1 == nullptr)
        for (; ptr2 != nullptr; ptr2 = ptr2->next)
        {
            ptr->next = new ListNode(ptr2->val);
            ptr = ptr->next;
        }

    else
        for (; ptr1 != nullptr; ptr1 = ptr1->next)
        {
            ptr->next = new ListNode(ptr1->val);
            ptr = ptr->next;
        }
    return head->next;
}

ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(0), *ptr = head, *ptr1, *ptr2;
    for (ptr1 = l1, ptr2 = l2; ptr1 != nullptr && ptr2 != nullptr;)
    {
        if (ptr1->val <= ptr2->val)
        {
            ptr->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    if (ptr1 == nullptr)
        ptr->next = ptr2;
    else

        ptr->next = ptr1;
    return head->next;
}