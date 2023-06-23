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
void insertAt( Node *head, int position, int value )
{
    Node *newnode = new Node( value );
    Node *current = head;
    for( int i = 1; i < position; i++ )
    {
        current = current->next;
    }
    newnode->next = current->next;
    newnode->prev = current;
    current->next->prev = newnode;
    current->next = newnode;

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
int main()
{
    Node *head = new Node( 10 );
    Node *a = new Node( 20 );
    Node *b = new Node( 30 );
    Node *c = new Node( 40 );
    Node *tail = c;

    //connections
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;

    int position, value;
    cin >> position >> value;
    if( position >= size( head ) )
    {
        cout << "Invalid" << endl;
    }
    else 
    {
        insertAt( head, position, value );
    }
    print( head );    
    cout << endl;
    printReverse( tail );
    return 0;
}
