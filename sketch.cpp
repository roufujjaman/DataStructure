#include <bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int value;
        Node* next;
        Node( int value )
        {
            this->value = value;
            this->next = NULL;
        }
};
void push( Node* &head, Node* &tail, int value )
{
    Node* newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void insertAtHead( Node* &head, Node* &tail, int value )
{
    Node* newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
int main()
{
    // Write your code here
    Node* head = NULL;
    Node* tail = NULL;
    int count, x, v;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> x >> v;
        if( x ==  0 )
        {
            insertAtHead( head, tail, v );
        }
        else
        {
            push( head, tail, v );
        }
        cout << head->value << ' ' << tail->value << endl;
    }
    return 0;
}