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
void print( Node *head )
{
    Node *current = head;
    while( current != NULL )
    {
        cout << current->value << ' ';
        current = current->next;
    }
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
    print( head );
    cout << endl;
    Node *fast = head;
    Node *slow = head;
    while( fast != NULL && fast->next != NULL )
    {
        // cout << slow->value << ' ' << fast->value << endl;
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->value;

    return 0;
}

// Input: head = [1,2,3,4,5]
// Output: [3]
// Explanation: The middle node of the list is node 3.
// Input: head = [1,2,3,4,5,6]
// Output: [4]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
