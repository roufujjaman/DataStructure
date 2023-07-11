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
            this->next = NULL;
            this->prev = NULL;
        }
};
class Stack
{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int stackSize = 0;
        void push( int val )
        {
            Node *new_node = new Node( val );
            stackSize++;
            if( head == NULL )
            {
                head = new_node;
                tail = new_node;
                return;
            }
            tail->next = new_node;
            new_node->prev = tail;
            tail = tail->next;
        }
        void pop()
        {
            Node *delete_node = tail;
            stackSize--;
            tail = tail->prev;
            delete delete_node;
            if( tail == NULL )
            {
                head = NULL;
                return;
            }
            tail->next = NULL;
        }
        int top()
        {
            return tail->val;
        }
        int size()
        {
            return stackSize;
        }
        bool empty()
        {
            if( stackSize ) return false;
            else return true;
        }
};
bool stackCompare( Stack obj_one, Stack obj_two )
{
    if( obj_one.size() != obj_two.size() ) return false;
    while( !obj_one.empty() )
    {
        if( obj_one.top() != obj_two.top() ) return false;
        obj_one.pop();
        obj_two.pop();
    }
    return true;
}
int main()
{
    Stack obj_one;
    Stack obj_two;
    int count, inputVal;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> inputVal;
        obj_one.push( inputVal );
    }
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> inputVal;
        obj_two.push( inputVal );
    }
    stackCompare( obj_one, obj_two )? cout << "YES" : cout << "NO"; // O(N)
    return 0;
}
