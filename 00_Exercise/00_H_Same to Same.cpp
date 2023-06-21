#include <bits/stdc++.h>

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
void push( Node* &head, Node* &tail, int value )
{
    Node* newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
int listLength( Node* head )
{
    Node* current = head;
    int count = 0;
    while( current != NULL )
    {
        count++;
        current = current->next;
    }
    return count;
}
bool listCompare( Node* headOne, Node* headTwo )
{
    int list_1_length = listLength( headOne );
    int list_2_length = listLength( headTwo );
    if( list_1_length != list_2_length ) return false;
    for( Node* i = headOne, *j = headTwo; i != NULL; i = i->next, j = j->next )
    {
        if( i->value != j-> value ) return false;
    }
    return true;
}
int main()
{
    // Write your code here
    Node* headOne = NULL;
    Node* tailOne = NULL;
    Node* headTwo = NULL;
    Node* tailTwo = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        push( headOne, tailOne, inputVal );
    }
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        push( headTwo, tailTwo, inputVal );
    }
    listCompare( headOne, headTwo )? cout << "YES" : cout << "NO";
    return 0;
}

// Sample Input 0

// 10 20 30 40 -1
// 10 20 30 40 -1
// Sample Output 0

// YES
// Sample Input 1

// 10 20 30 40 -1
// 10 20 30 -1
// Sample Output 1

// NO
// Sample Input 2

// 10 20 30 40 -1
// 40 30 20 10 -1
// Sample Output 2

// NO