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
    for( int i = 0; i < position; i++ )
    {
        cout << i << ' ' << current->value << endl;
        current = current->next;
    }
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
    insertAt( head, 3 , 100 );
    print( head );    
    return 0;
}