#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *next;
        Node *prev;
        Node( int val )
        {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};
void print( Node *head )
{
    Node *current = head;
    while ( current != NULL )
    {
        cout << current->val << ' ';
        current = current->next;
    }
}
void printReverse( Node *tail )
{
    Node *current = tail;
    while( current != NULL )
    {
        cout << current->val << ' ';
        current = current->prev;
    }
}
void insertAt( Node *&head, int pos, int val )
{
    Node *newnode = new Node( val );
    Node *current = head;
    for( int i = 1; i < pos; i++ )
    {
        current = current->next;
    }
    newnode->next = current->next;
    newnode->prev = current;
    current->next->prev = newnode;
    current->next = newnode;
}
void insertAtTail( Node *&tail, int val )
{
    Node *newnode = new Node( val );
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}
void insertAtHead( Node *&head, Node *&tail, int val )
{
    Node *newnode = new Node( val );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
int main()
{
    vector<string> mystr;
    string inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == "end" ) break;
        mystr.push_back( inputVal );
    } 
    for( string val: mystr )
    {
        cout << val << endl;
    }
    return 0;
}