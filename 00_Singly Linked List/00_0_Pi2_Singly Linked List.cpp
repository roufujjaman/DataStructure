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
void push(  Node* &head, int value )
{
    Node* newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        cout << "new value added at head" << endl;
        return;
    }
    Node* current = head;
    while( current->next != NULL )
    {   
        current = current->next;
    }
    current->next = newnode;
    cout << "new value pushed" << endl;
}
void insertItem( Node* &head, int position, int value)
{
    Node* newnode = new Node( value );
    Node* current = head;
    if( position == 0 )
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    else
    {
        for ( int i = 1; i < position; i++)
        {
            if( current == NULL ) return;
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
        
    }
}
void deleteItem( Node* &head, int position, int items = 1 )
{
    if( position == 0 )
    {
        Node* delete_node = head;
        head = head->next;
        delete delete_node;
    }
    else
    {
        for( int i = 1; i < position; i++ )
        {
            
        }
    }
}
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
    Node* head = NULL;
    while( true )
    {
        int commandVal, inputVal, posVal;
        cin >> commandVal;
        if( commandVal == 0 )
        {
            break;
        }
        else if ( commandVal == 1 )
        {
            cin >> inputVal;
            push( head, inputVal );
        }
        else if( commandVal == 2 )
        {
            print( head );
        }
        else if ( commandVal == 3 )
        {
            cin >> posVal >> inputVal;
            insertItem( head, posVal, inputVal );
        }
        else if ( commandVal == 4 )
        {
            cin >> inputVal;
            deleteItem(head, inputVal );
        }
    }
    return 0;
}