#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *next;
        Node *prev;
        Node( int val )
        {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
}
class myStack
{
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push( int val )
    {
        sz++;
        Node *new_node = new Node( val );
        if( head == NULL )
        {
            head = newnode;
            tail = newnode;
            return;
        }
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    void pop()
    {
        sz--;
        Node *delete_node = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete delete_node;
    }
}
int main()
{
    ;
    return 0;
}