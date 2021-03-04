#include <iostream>
#include <vector>
#include "data_structure.hpp"

using namespace std;

ListNode *reverseList(ListNode *head);
ListNode *reverseList2(ListNode *head);
ListNode *reverseList3(ListNode *head);

int main(int argc, char const *argv[])
{
    //int arr[] = {1, 2, 3, 4, 5, 6};
    //ListNode *head = init_list(arr, sizeof(arr) / sizeof(int));
    vector<int> v = {1, 2, 3, 4, 5, 6};
    ListNode *head = init_list(v);
    print_list(head);
    head = reverseList3(head);
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

ListNode *reverseList2(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    vector<ListNode *> v;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        v.push_back(ptr);
    for (int i = v.size() - 1; i > 0; i--)
        v[i]->next = v[i - 1];
    v[0]->next = nullptr;
    return v[v.size() - 1];
}

ListNode *reverseList3(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
