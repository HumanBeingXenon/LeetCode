#include <iostream>
#include <deque>
#include <vector>
#include "data_structure.hpp"

using namespace std;

bool isPalindrome(ListNode *head);
bool isPalindrome2(ListNode *head);

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 3, 2, 1};
    int arr2[] = {1, 2, 3, 3, 3, 1};
    ListNode *head = init_list(arr, sizeof(arr) / sizeof(int));
    ListNode *head2 = init_list(arr2, sizeof(arr) / sizeof(int));

    print_list(head);
    print_list(head2);

    cout << (isPalindrome2(head) ? "true" : "false") << " " << (isPalindrome2(head2) ? "true" : "false") << endl;

    print_list(head);
    print_list(head2);
    return 0;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    deque<ListNode *> dq;
    ListNode *ptr = head;
    while (ptr)
    {
        dq.push_front(ptr);
        ptr = ptr->next;
    }
    while (!dq.empty())
    {
        ListNode *front = dq.front();
        ListNode *back = dq.back();
        if (front->val == back->val)
        {
            dq.pop_front();
            dq.pop_back();
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome2(ListNode *head)
{
    if (!head || !head->next)
        return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *last = slow->next, *pre = head;
    while (last->next)
    {
        ListNode *tmp = last->next;
        last->next = tmp->next;
        tmp->next = slow->next;
        slow->next = tmp;
    }
    while (slow->next)
    {
        slow = slow->next;
        if (pre->val != slow->val)
            return false;
        pre = pre->next;
    }
    return true;
}

bool isPalindrome3(ListNode *head)
{
    vector<ListNode *> v;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        v.push_back(ptr);
    }
    int len = v.size();
    for (int i = 0; i < len / 2; i++)
        if (v[i]->val != v[len - i - 1]->val)
            return false;
    return true;
}