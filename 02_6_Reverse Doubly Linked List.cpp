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
void print( Node* head )
{
    Node* current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->next;
    }
}
void insertTail( Node *&head, Node *&tail, int value ) //<<<<<<<<
{
    Node *newnode = new Node( value );
    if( tail == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = tail->next;
}
void reverse( Node *head, Node *tail )
{
    Node *i = head;
    Node *j = tail;
    while( i != j  &&  i->prev != j )
    {
        swap( i->value, j->value );
        i = i->next;
        j = j->prev;
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
    reverse( head, tail );
    cout << endl;
    print( head );
    return 0;
}
