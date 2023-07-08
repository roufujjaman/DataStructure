#include <bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int val;
        Node *next;
        Node( int val )
        {
            this->val = val;
            this->next = NULL;
        }
};
class List
{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        void push_back( int val )
        {
            Node *new_node = new Node( val );
            if( head == NULL )
            {
                head = new_node;
                tail = new_node;
                return;
            }
            tail->next = new_node;
            tail = tail->next;
        }
};
class Stack
{
    public:
        Node *head = NULL;
        int sz = 0;
        void push( int val )
        {
            Node *new_node = new Node( val );
            sz++;
            if( head == NULL )
            {
                head = new_node;
                return;
            }
            new_node->next = head;
            head = new_node;
        }
        void pop()
        {
            if( head == NULL ) return;
            Node *delete_node = head;
            sz--;
            head = head->next;
            delete delete_node;
        }
        int top()
        {
            return head->val;
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
class Queue
{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz = 0;
        void push( int val )
        {
            Node *new_node = new Node( val );
            sz++;
            if( head == NULL )
            {
                head = new_node;
                tail = new_node;
                return;
            }
            tail->next = new_node;
            tail = tail->next;
        }
        void pop()
        {
            if( head == NULL ) return;
            Node *delete_node = head;
            sz--;
            head = head->next;
            if( head == NULL ) tail = NULL;
            delete delete_node;
        }
        int front()
        {
            return head->val;
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
    // Write your code here
    int n, m, inputVal;
    Stack objN;
    Queue objM;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        cin >> inputVal;
        objN.push( inputVal );
    }
    for( int i = 0; i < m; i++ )
    {
        cin >> inputVal;
        objM.push( inputVal );
    }
    if( objN.size() != objM.size() )
    {
        cout << "NO";
        return 0;
    }
    
    List listN;
    List listM;
    while( !objN.empty() )
    {
        listN.push_back( objN.top() );
        objN.pop();
    }
    while( !objM.empty() )
    {
        listM.push_back( objM.front() );
        objM.pop();
    }
    bool found = true;
    for( auto n = listN.head, m = listM.head; n != NULL; n = n->next , m = m->next )
    {
        if( n->val != m->val )
        {
            found = false;
        };
    }
    if( found ) cout << "YES";
    else cout << "NO";
    return 0;
}