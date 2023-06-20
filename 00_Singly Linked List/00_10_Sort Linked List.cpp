#include<bits/stdc++.h>
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
    }
    tail->next = newnode;
    tail = newnode;
}
void print( Node* head )
{
    for( Node* i = head; i != NULL; i = i->next )
    {
        cout << i->value << ' ';
    }
}
void sortList( Node* head )
{
    for( Node* i = head; i->next != NULL; i = i->next )
    {
        for( Node* j = i->next; j != NULL; j = j->next )
        {
            if( i->value > j->value )
            {
                swap( i->value, j->value );
            }
        }
    }
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int commandVal, inputVal;
    while( true )
    {
        cin >> commandVal;
        if( commandVal == 0 )
        {
            break;
        }
        else if ( commandVal == 1 )
        {
            cin >> inputVal;
            push( head, tail, inputVal );
        }
        else if( commandVal == 2 )
        {
            print( head );
        }
        else if ( commandVal == 3 )
        {
            sortList( head );
        }
    }
    return 0;
}