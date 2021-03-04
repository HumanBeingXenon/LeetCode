#include <iostream>
#include <vector>
#include <unordered_set>
#include "data_structure.hpp"

using namespace std;

ListNode *make_cycle(int arr[], int len, int idx);
bool hasCycle(ListNode *head);
bool hasCycle2(ListNode *head);

int main(int argc, char const *argv[])
{
    int arr[] = {3, 2, 0, -4};
    ListNode *head = make_cycle(arr, sizeof(arr) / sizeof(int), -1);
    cout << (hasCycle2(head) ? "true" : "false") << endl;
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

bool hasCycle(ListNode *head)
{
    unordered_set<ListNode *> set;
    ListNode *ptr = head;
    while (ptr)
    {
        if (set.count(ptr))
            return true;
        else
            set.insert(ptr);
        ptr = ptr->next;
    }
    return false;
}

bool hasCycle2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

bool hasCycle3(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *slow = head, *fast = head;
    do
    {
        if (fast == nullptr || fast->next == nullptr)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    return true;
}
