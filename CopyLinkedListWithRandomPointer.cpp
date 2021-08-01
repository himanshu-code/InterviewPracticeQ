#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int val)
    {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{
    Node *temp = head;
    while (temp != NULL) //Making copy of node and placing them between list;
    {
        Node *n = new Node(temp->val);
        n->next = temp->next;
        temp->next = n;
        temp = temp->next->next;
    }
    temp = head;
    while (temp != NULL) //making connection between copied nodes
    {
        if (temp != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }
    temp = head;
    Node *new_head = NULL, *new_tail = NULL;
    while (temp != NULL) //removing connections between copied nodes and orginal list
    {
        Node *copy = temp->next;
        if (new_head == NULL)
        {
            new_head = copy;
            new_tail = copy;
            temp->next = copy->next;
            copy->next = NULL;
        }
        else
        {
            temp->next = copy->next;
            copy->next = NULL;
            new_tail->next = copy;
            new_tail = copy;
        }
        temp = temp->next;
    }
    return new_head;
}
int main()
{
}
