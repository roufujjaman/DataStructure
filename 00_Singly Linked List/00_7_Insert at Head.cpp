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
        cout << "node created" << endl;
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
void insert_at( Node * head, int position, int value ) // will crash if position goes out of range
{
    Node * newNode = new Node(value);
    Node * current = head;
    for( int i = 1; i <= position - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    cout << "- inserted " << value << " at " << position << endl;
}
void insert_at_head( Node * &head, int value ) // <<<head input should be pointer + reference to be reassigned by a new Node>>>
{
    Node * newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    cout << "- inserted at head" << endl;
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
int main()
{
    Node * head = NULL;
    cout << "option 0 - terminate" << endl;
    cout << "option 1 - insert_at_tail()" << endl;
    cout << "option 2 - insert_at()" << endl;
    cout << "option 3 - print_linked_list()" << endl;
    cout << "option 4 - insert_at_head()" << endl;
    int option;
    while( option != 0 )
    {
        cin >> option;
        if( option == 0 )
        {
            break;
        }
        else if( option == 1 )
        {
            int value;
            cout << "insert value: ";
            cin >> value;
            insert_at_tail(head, value);
        }
        else if( option == 2 )
        {
            int position, value;
            cout << "insert position, value: ";
            cin >> position >> value;
            insert_at(head, position, value);
        }
        else if( option == 3 )
        {
            cout << "LinkedList - ";
            print_linked_list(head);
            cout << endl;
        }
        else if( option == 4 )
        {
            int value;
            cout << "insert position, value: ";
            cin >> value;
            insert_at_head(head, value);
        }

    }
    return 0;
}