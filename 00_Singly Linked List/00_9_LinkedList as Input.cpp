#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node * next;

        Node( int value )
        {
            this->value = value;
            this->next = NULL;
        }
};
void insert_at_tail( Node * &head, int value ) // <<<head input should be pointer + reference to be reassigned by a new Node>>>
{
    Node * newNode = new Node(value);
    if( head == NULL )
    {
        head = newNode;
        cout << "- node created" << endl;
        return;
    }
    Node * current = head;
    while( current->next != NULL )
    {
        current = current->next;
    }
    current->next = newNode;
    cout << "- inserted at tail" << endl;
}
void print_linked_list( Node * head )
{
    Node * temp = head;
    while( temp != NULL )
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
int main ()
{
    int value;
    Node * head = NULL;
    while ( true )
    {
        cin >> value;
        if( value == -1)
        {
            break;
        }
        else
        {
            insert_at_tail( head, value );
        }
    }
    print_linked_list(head);
    return 0;
}