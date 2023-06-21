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
int listLength( Node* head )
{
    Node* current = head;
    int count = 0;
    while( current != NULL )
    {
        count++;
        current = current->next;
    }
    return count;
}
void printAt( Node* head, int position )
{
    Node* current = head;
    int count = 0;
    while( current != NULL )
    {
        if( count == position )
        {
            cout << current->value;
        }
        count++;
        current = current->next;
    }
}
void listSort( Node* head )
{
    for( Node* i = head; i->next != NULL; i = i->next )
    {
        for( Node* j = i->next; j != NULL; j = j->next )
        {
            if( i->value < j->value )
            {
                swap( i->value, j->value );
            }
        }
    }
}
int main()
{
    // Write your code here
    Node* head = NULL;
    Node* tail = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        push( head, tail, inputVal );
    }
    listSort( head );
    int length = listLength( head );
    if ( length % 2 == 1 )
    {
        printAt( head, length / 2);
    }
    else
    {
        printAt( head, length / 2 - 1 );
        cout << ' ';
        printAt( head, length / 2 );
    }
    return 0;
}