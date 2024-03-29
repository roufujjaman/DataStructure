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
void insert_at_tail( Node * &head, int value ) // <<<head input should be pointer + reference to be reassigned by a Node object>>>
{
    Node * newNode = new Node(value);
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    Node * temp = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void print_linked_list( Node * head )
{
    Node * temp = head;
    while( temp != NULL )
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
int main()
{
    Node * head = NULL;
    cout << "option 0 - terminate" << endl;
    cout << "option 1 - insert_at_tail()" << endl;
    cout << "option 2 - print_linked_list()" << endl;
    int option;
    while( option != 0 )
    {
        cin >> option;
        if( option == 0 )
        {
            break;
        }
        else if ( option == 1 )
        {
            int value;
            cout << "insert value: ";
            cin >> value;
            insert_at_tail(head, value);
        }
        else if ( option == 2 )
        {
            cout << "- Linked List -" << endl;
            print_linked_list(head);
        }
    }
    return 0;
}