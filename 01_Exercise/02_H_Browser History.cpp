#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        string val;
        Node *next;
        Node *prev;
        Node( string val )
        {
            this->val = val;
            this->next = NULL;
            this->next = NULL;
        }
};
void insert( Node *&head, Node *&tail, string val )
{
    Node *newnode = new Node( val );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}
void goTo( Node *head, Node *&current, string val, bool *isFound )
{
    for( Node *i = head; i != NULL; i = i->next )
    {
        if( i->val == val )
        {
            current = i;
            *isFound = true;
            break;
        }
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    
    string inputVal;
    string positionVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == "end" ) break;
        insert( head, tail, inputVal );
    }
    Node *current;
    int count;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> inputVal;
        if( inputVal == "visit" )
        {
            cin >> positionVal;
            bool isFound = false;
            goTo( head, current, positionVal, &isFound );
            if( isFound ) cout << current->val << endl;
            else cout << "Not Available" << endl;
        }
        else if( inputVal == "next" && current->next != NULL )
        {
            current = current->next;
            cout << current->val << endl;
        }
        else if( inputVal == "prev" && current->prev != NULL )
        {
            current = current->prev;
            cout << current->val << endl;
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }
    return 0;
}