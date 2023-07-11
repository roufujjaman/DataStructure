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
int listSize( Node *head )
{
    int count = 0;
    Node *current = head;
    while( current != NULL )
    {
        count++;
        current = current->next;   
    }
    return count;
}
bool listCompare( Node *head_one, Node *head_two )
{
    if( listSize( head_one ) != listSize( head_two ) ) return false;
    for( Node *i = head_one, *j = head_two; i != NUll; i = i->next, j = j->next )
    {
        if( i->value != j->value ) return false;
    }
    return true;
}
// bool listCompare( Node *head_one, Node *head_two )
// {
//     if( listSize( head_one ) != listSize( head_two ) ) return false;
//     Node *current_one = head_one;
//     Node *current_two = head_two;
//     while( current_one != NULL )
//     {
//         if( current_one->value != current_two->value ) return false;
//         current_one = current_one->next;
//         current_two = current_two->next;
//     }
//     return true;
// }
int main()
{
    Node *head_one = NULL;
    Node *tail_one= NULL;
    Node *head_two = NULL;
    Node *tail_two = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertTail( head_one, tail_one, inputVal );
    }
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertTail( head_two, tail_two, inputVal );
    }
    listCompare( head_one, head_two )? cout << "YES" : cout << "NO";
    return 0;
}
