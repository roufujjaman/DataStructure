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
void sortList( Node *head ) //O(N^2)
{
    for( Node *i = head; i->next != NULL; i = i->next )
    {
        for( Node *j = i->next; j != NULL; j = j->next )
        {
            if( i->value > j->value ) swap( i->value, j->value );
        }
    }
    // Node *i = head;
    // Node *j = NULL;
    // while ( i->next != NULL )
    // {
    //     for( j = i->next; j != NULL; j = j->next )
    //     {
    //         if( i->value > j->value ) swap( i->value, j->value );
    //     }
    //     i = i->next;
    // }
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
    sortList( head );
    print( head );
    return 0;
}
