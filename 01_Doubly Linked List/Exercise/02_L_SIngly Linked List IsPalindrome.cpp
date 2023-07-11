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
void print( Node *head )
{
    Node *current = head;
    while( current != NULL )
    {
        cout <<  current->value << ' ';
        current = current->next;
    }
    cout << endl;
}
void insertAtTail( Node *&head, Node *&tail, int value )
{
    Node *newnode = new Node( value );
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
int main()
{
    Node *head_one = NULL;
    Node *tail_one = NULL;
    Node *head_two = NULL;
    Node *tail_two = NULL;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        insertAtTail( head_one, tail_one, inputVal );
    }
    
    print( head_one );
    
    Node *current_one = head_one;
    while ( current_one != NULL )
    {
        insertAtTail( head_two, tail_two, current_one->value );
        current_one = current_one->next;   
    }
    
    listReverse( head_two, head_two );
    print( head_two );
    
    current_one = head_one;
    Node *current_two = head_two;
    bool isPalindrome = true;
    while( current_one != NULL )
    {
        if( current_one->value != current_two->value )
        {
            isPalindrome = false;
        }
        current_one = current_one->next;
        current_two = current_two->next;
    }
    isPalindrome? cout << "palindrome - YES" : cout << "palindrome - NO"; 
    return 0;
}
