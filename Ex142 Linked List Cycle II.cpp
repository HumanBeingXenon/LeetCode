#include <iostream>
#include <vector>
#include <unordered_set>
#include "data_structure.hpp"

using namespace std;

ListNode *make_cycle(int arr[], int len, int idx);
ListNode *hasCycle(ListNode *head);
bool hasCycle2(ListNode *head);

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 0, -4};
    ListNode *head = make_cycle(arr, sizeof(arr) / sizeof(int), 2);
    ListNode *cyclenode = hasCycle(head);
    cout << (cyclenode != nullptr ? cyclenode->val : -1) << endl;
    return 0;
}

ListNode *make_cycle(int arr[], int len, int idx)
{
    ListNode *head = new ListNode(0), *prev = head;
    ListNode *cyclepoint;
    for (int i = 0; i < len; i++)
    {
        ListNode *node = new ListNode(arr[i]);
        prev->next = node;
        prev = node;
        if (i == idx)
            cyclepoint = node;
    }
    if (idx != -1)
        prev->next = cyclepoint;
    return head->next;
}

ListNode *hasCycle(ListNode *head)
{
    unordered_set<ListNode *> set;
    ListNode *ptr = head;
    while (ptr)
    {
        if (set.count(ptr))
            return ptr;
        else
            set.insert(ptr);
        ptr = ptr->next;
    }
    return nullptr;
}