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
    Node* current = head;
    if( position == 0 )
    {
        head = head->next;
        delete current;
    }
    else
    {
        for( int i = 1; i < position; i++ )
        {
            current = current->next;
            if( current->next == NULL )
            {
                cout << "came here";
                return;
            }
        }
        Node* delete_node = current->next;
        current->next = current->next->next;
        delete delete_node;
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
int len(Node* head)
{
    int count = 0 ;
    Node* current = head;
    while( current != NULL )
    {
        current = current->next;
        count++;
    }
    return count;
}
bool checkDup( Node* head )
{
    int arr[100] = {0};
    Node* current = head;
    while( current != NULL )
    {
        arr[ current->value - 1 ]++;
        current = current->next;
    }
    for( int i = 0; i < 100; i++ )
    {
        if( arr[i] > 1 ) 
        {
            return true;
        };
    }
    return false;
}
int printByIndex( Node* head, int position )
{
    Node* current = head;
    for( int  i = 0; i < position; i++ )
    {
        current = current->next;
    }
    return current->value;   
}
bool isSorted( Node* head )
{
    Node* current = head;
    while( true )
    {
        if( current->next == NULL ) break;
        if( current->value > current->next->value )
        {
            return false;
        }
    }
    return true;
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
            cout << endl;
            cout << "Size : " << len( head ) << endl;
            checkDup( head )? cout << "Duplicate : YES" << endl : cout << "Duplicate : NO" << endl;
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
        else if ( commandVal == 5 )
        {
            int list_length = len(head);
            if( list_length % 2 == 1 )
            {
                cout << "Middle - "<< printByIndex( head, list_length / 2 ) << endl;
            }
            else
            {
                cout << "Middle - " << printByIndex( head, list_length / 2 - 1 ) << endl;
                cout << "Middle - " << printByIndex( head, list_length / 2 ) << endl;
            }
        }
        else if ( commandVal == 6 )
        {
            isSorted( head )? cout << "Sorted" << endl : cout << "Unsorted" << endl;
        }
    }
    return 0;
}
