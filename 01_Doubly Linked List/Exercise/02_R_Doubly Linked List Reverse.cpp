#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node *next;
        Node *prev;
        Node( int value )
        {
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};
void insertTail( Node *&head, Node *&tail, int value )
{
    Node *newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void print( Node *head )
{
    Node *current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->next;
    }
}
void reverseList( Node *head, Node *tail )
{
    for( Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev )
    {
        swap( i->value, j->value );
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertTail( head, tail, inputVal );
    }
    reverseList( head, tail );
    print( head )
    return 0;
}
