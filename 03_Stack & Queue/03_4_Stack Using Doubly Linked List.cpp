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
};
class myStack
{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push( int val )
    {
        sz++;
        Node *new_node = new Node( val );
        if( head == NULL )
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    void pop()
    {
        Node *delete_node = tail;
        sz--;
        tail = tail->prev;
        if( tail == NULL ) head = NULL;
        delete delete_node;
    }
    int top()
    {
        // if( tail == NULL ) return;
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if( sz == 0 ) return true;
        else return false; 
    }
};
int main()
{
    myStack obj;
    int count, input_val;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {   
        cin >> input_val;
        obj.push( input_val );
    }
    while ( !obj.empty() )
    {
        cout << obj.top() << ' ';
        obj.pop();
    }
    return 0;
}

