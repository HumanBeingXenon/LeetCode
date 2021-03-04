#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

ListNode *reverseList(ListNode *head);
ListNode *reverseBetween(ListNode *head, int m, int n);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode *head = init_list(arr, sizeof(arr) / sizeof(int));
    print_list(head);
    head = reverseBetween(head, 2, 6);
    print_list(head);
    return 0;
}

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *tail = head;
    while (tail->next != nullptr)
    {
        ListNode *temp = tail->next;
        tail->next = temp->next;
        temp->next = head;
        head = temp;
    }
    return head;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode *tmphead = new ListNode(0, head);
    ListNode *ptr = tmphead;
    for (int i = 1; i < m; i++)
        ptr = ptr->next;
    ListNode *tail = ptr->next;
    for (int i = m; i < n; i++)
    {
        ListNode *temp = tail->next;
        tail->next = temp->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    return tmphead->next;
}