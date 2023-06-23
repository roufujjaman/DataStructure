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
void deleteAt( Node *head, int position )
{
    Node *current = head;
    for( int i = 1; i < position; i++ )
    {
        current = current->next;
    }
    Node * deletenode = current->next;
    current->next = current->next->next;
    current->next->prev = current; // since current->next is changed in previous line
    delete deletenode;
}
void deleteTail( Node *&tail )
{
    Node *deletenode = tail;
    tail = tail->prev;
    tail->next = NULL; // since tail is changed 
    delete deletenode;
}
void deleteHead( Node *&head )
{
    Node *deletenode = head;
    head = head->next;
    head->prev = NULL; //since head is changed
    delete deletenode;
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

    int position;
    cin >> position;
    if( position >= size( head ) )
    {
        cout << "invalid" << endl;
    }
    else if ( position == 0 )
    {
        deleteHead( head );
    }
    else if( position == size( head ) - 1 )
    {
        deleteTail( tail );
    }
    else
    {
        deleteAt( head, position );
    }
    print( head );    
    cout << endl;
    printReverse( tail );
    return 0;
}
