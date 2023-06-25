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
int main()
{
    Node *head = new Node( 10 );
    Node *a = new Node( 20 );
    Node *b = new Node( 30 );
    Node *c = new Node( 40 );
    
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = a;

    bool cycle_detected = false;
    Node *slow = head;
    Node *fast = head;
    while( fast != NULL && fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
        if( fast == slow )
        {
            cycle_detected = true ;
            break;
        }
    }

    if( cycle_detected ) cout << "cycle detected";
    else cout << "no cycle detected";
    return 0;
}
