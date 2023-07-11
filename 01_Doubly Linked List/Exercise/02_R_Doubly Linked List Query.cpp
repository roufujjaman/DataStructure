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
void insertHead( Node *&head, Node *&tail, int value )
{
    Node *newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
int listSize( Node *head ) // O(N)
{
    int count = 0;
    Node *current = head;
    while( current != NULL )
    {
        count++;
        current = current->next;   
    }
    return count;
}
void insertAtPosition( Node *head, Node *&tail, int position, int value )
{
    // if ( position > listSize( head ) ) // O(N)
    // {
    //     cout << "invalid" << endl;
    //     return;
    // }
    Node *newnode = new Node ( value );
    if( position == listSize( head ) ) // O(N) + O(1)
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        return;
    }
    Node *current = head;
    for( int i = 1; i < position; i ++ )
    {
        current = current->next;
    }
    newnode->next = current->next;
    newnode->prev = current;
    current->next->prev = newnode;
    current->next = newnode;
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
void printReverse( Node *tail )
{
    Node *current = tail;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->prev;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int count, positionVal, inputVal;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> positionVal >> inputVal;
        if( positionVal == 0 )
        {
            insertHead( head , tail, inputVal );
        }
        else if ( positionVal > listSize( head ) )
        {
            cout << "invalid" << endl;
            continue;
        }
        else    
        {
            insertAtPosition( head, tail, positionVal, inputVal );
        }
        print( head );
        cout << endl;
        printReverse( tail );
        cout << endl;
    }
    return 0;
}
