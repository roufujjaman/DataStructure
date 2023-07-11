#include <bits/stdc++.h>
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
void print( Node *head )
{
    Node *current = head;
    while ( current != NULL )
    {
        cout << current->val << ' ';
        current = current->next;
    }
}
void printReverse( Node *tail )
{
    Node *current = tail;
    while( current != NULL )
    {
        cout << current->val << ' ';
        current = current->prev;
    }
}
void insertAt( Node *&head, int pos, int val )
{
    Node *newnode = new Node( val );
    Node *current = head;
    for( int i = 1; i < pos; i++ )
    {
        current = current->next;
    }
    newnode->next = current->next;
    newnode->prev = current;
    current->next->prev = newnode;
    current->next = newnode;
}
void insertAtTail( Node *&tail, int val )
{
    Node *newnode = new Node( val );
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}
void insertAtHead( Node *&head, Node *&tail, int val )
{
    Node *newnode = new Node( val );
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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;
    int count, queryVal, inputVal;
    cin >> count;
    for ( int i = 0; i < count; i++ )
    {
        cin >> queryVal >> inputVal;
        if( queryVal > size )
        {
            cout << "Invalid" << endl;
            continue;
        }
        else if( queryVal == 0 )
        {
            insertAtHead( head, tail, inputVal );
            size++;
        }
        else if( queryVal == size && queryVal > 0)
        {
            insertAtTail( tail, inputVal );
            size++;
        }
        else
        {
            insertAt( head, queryVal, inputVal );
            size++;
        }
        cout << "L -> ";
        print( head );
        cout << endl;
        
        cout << "R -> ";
        printReverse( tail );
        cout << endl;
    }
    return 0;
}


// Sample Output 1

// L -> 10 
// R -> 10 
// L -> 10 20 
// R -> 20 10 
// L -> 30 10 20 
// R -> 20 10 30 
// L -> 30 40 10 20 
// R -> 20 10 40 30 
// Invalid
// L -> 60 30 40 10 20 
// R -> 20 10 40 30 60 
// L -> 60 30 40 10 70 20 
// R -> 20 70 10 40 30 60 
// L -> 60 30 40 10 80 70 20 
// R -> 20 70 80 10 40 30 60 
// L -> 60 30 90 40 10 80 70 20 
// R -> 20 70 80 10 40 90 30 60 
// L -> 60 100 30 90 40 10 80 70 20 
// R -> 20 70 80 10 40 90 30 100 60 