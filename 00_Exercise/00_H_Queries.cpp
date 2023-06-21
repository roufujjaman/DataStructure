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
void insertAtHead( Node* &head, Node* &tail, int value )
{
    Node* newnode = new Node( value );
    if( head == NULL )
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}
int main()
{
    // Write your code here
    Node* head = NULL;
    Node* tail = NULL;
    int count, x, v;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {
        cin >> x >> v;
        if( x ==  0 )
        {
            insertAtHead( head, tail, v );
        }
        else
        {
            push(head, tail, v);
        }
        cout << head->value << ' ' << tail->value << endl;
    }
    return 0;
}

// Sample Input 0

// 5
// 0 10
// 0 20
// 1 30
// 0 40
// 1 50
// Sample Output 0

// 10 10
// 20 10
// 20 30
// 40 30
// 40 50
// Explanation 0

// Query 1: 10 is inserted at head. Linked list looks like: 10->NULL. Now both head and tail are 10.
// Query 2: 20 is inserted at head. Linked list looks like: 20->10->NULL. Now head is at 20 and tail is at 10.
// Query 3: 30 is inserted at tail. Linked list looks like: 20->10->30->NULL. Now head is at 20 and tail is at 30.
// Query 4: 40 is inserted at head. Linked list looks like: 40->20->10->30->NULL. Now head is at 40 and tail is at 30.
// Query 5: 50 is inserted at tail. Linked list looks like: 40->20->10->30->50->NULL. Now head is at 40 and tail is at 50.
// Sample Input 1

// 3
// 1 10
// 1 20
// 0 30
// Sample Output 1

// 10 10
// 10 20
// 30 20
// Explanation 1

// Query 1: 10 is inserted at tail. Linked list looks like: 10->NULL. Now both head and tail are 10.
// Query 2: 20 is inserted at tail. Linked list looks like: 10->20->NULL. Now head is at 10 and tail is at 20.
// Query 3: 30 is inserted at head. Linked list looks like: 30->10->20->NULL. Now head is at 30 and tail is at 20.