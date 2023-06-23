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
void print( Node* head )
{
    Node* current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->next;
    }
}
int main()
{
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    //connections
    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    print( head );
    return 0;
}
