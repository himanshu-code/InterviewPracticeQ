#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
        return head->next;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}
int main()
{
}