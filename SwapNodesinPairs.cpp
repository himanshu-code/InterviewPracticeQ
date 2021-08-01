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
ListNode *swapPairs(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    ListNode *next_pair = swapPairs(head->next->next);
    ListNode *temp = head->next;
    temp->next = head;
    head->next = next_pair;
    return temp;
}
int main()
{
}