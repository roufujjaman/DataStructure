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
void listReverse( Node *&head, Node *current )
{
    if( current->next == NULL )
    {
        head = current;
        return;
    }
    listReverse( head, current->next );
    current->next->next = current;
    current->next = NULL;
}
bool isPalindrome( Node *head_one, Node *head_two )
{
    Node *currentOne = head_one;
    Node *currentTwo = head_two;
    while( currentOne != NULL )
    {
        if( currentOne->val != currentTwo->val ) return false;
        currentOne = currentOne->next;
        currentTwo = currentTwo->next;
    }
    return true;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    
    Node *headCpy = NULL;
    Node *tailCpy = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertAtTail( head, tail, inputVal );
        insertAtTail( headCpy, tailCpy, inputVal);
    }
    listReverse( headCpy, headCpy );
    isPalindrome( head, headCpy )? cout << "YES": cout << "NO";
    return 0;
}