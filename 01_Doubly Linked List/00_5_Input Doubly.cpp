#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* next;
        Node* prev;
        Node( int value )
        {
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};
void print( Node *head )
{
    Node* current = head;
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
int size( Node *head )
{
    Node *current = head;
    int count = 0;
    while ( current != NULL )
    {
        count++;
        current = current->next;
    }
    return count;    
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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int inputVal;
    while ( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertTail( head, tail, inputVal );
    }
    print( head );    
    cout << endl;
    printReverse( tail );
    return 0;
}
