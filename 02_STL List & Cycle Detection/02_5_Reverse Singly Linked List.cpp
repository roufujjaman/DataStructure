#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node *next;
        Node( int value )
        {
            this->value = value;
            this->next = NULL;
        }
};
void print( Node *head )
{
    Node *current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
    }
}
void reverse( Node *&head, Node *current )
{
    if( current->next == NULL )
    {  
        head = current;
        return;
    }
    reverse( head, current->next );
    current->next->next = current;
    current->next = NULL;
}
int main()
{
    Node *head = new Node( 100 );
    Node *a = new Node( 200 );
    Node *b = new Node( 300 );

    //connection
    head->next = a;
    a->next = b;
    reverse( head, head );
    Node *current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->next;
    }
    return 0;
}