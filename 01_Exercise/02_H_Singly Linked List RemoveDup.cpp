#include <bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int val;
        Node *next;
        Node( int val )
        {
            this->val = val;
            this->next = NULL;
        }
};
void listSort( Node *head )
{
    for( Node *i = head; i->next != NULL; i = i->next )
    {
        for( Node *j = i->next; j != NULL; j = j->next )
        {
            if( i->val > j->val )
            {
                swap( i->val, j->val );
            }
        }
    }
}
void insertAtTail( Node *&head, Node *&tail, int val )
{
    Node *newnode = new Node( val );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void deleteDup( Node *head )
{
    if( head == NULL ) return;
    Node *current = head;
    Node *deletenode;
    while( current->next != NULL )
    {
        if( current->val == current->next->val )
        {
            deletenode = current->next;
            current->next = current->next->next;
            delete deletenode;
            if( current->next != NULL && current->val == current->next->val ) continue;
        }
        if( current->next == NULL ) break;
        else current = current->next;
    }
}
void print( Node *head )
{
    Node *current = head;
    while( current != NULL )
    {
        cout << current->val << ' ';
        current = current->next;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertAtTail( head, tail, inputVal );
    }
    listSort( head );
    deleteDup( head );
    print( head );
    return 0;
}