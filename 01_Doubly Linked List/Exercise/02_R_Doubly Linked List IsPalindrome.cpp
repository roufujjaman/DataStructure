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
void insertTail( Node *&head, Node *&tail, int value )
{
    Node *newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
bool isPalindrome( Node *head, Node *tail )
{
    for( Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev )
    {
        if( i->value != j->value ) return false;
    }
    return true;
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
        insertTail( head, tail, inputVal );
    }
    isPalindrome( head, tail )? cout << "YES" : cout << "NO";
    return 0;
}
