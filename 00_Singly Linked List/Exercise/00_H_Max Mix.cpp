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
void findMinMax( Node* head, int* mx, int* mn )
{
    int min = INT_MAX;
    int max = INT_MIN;
    Node* current = head;
    while( current != NULL )
    {
        if( current->value <= min )
        {
            min = current->value;
        }
        if( current->value >= max )
        {
            max = current->value;
        }
        current = current->next;
    }
    *mx = max;
    *mn = min;
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int inputVal;
    int mx, mn; 
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        push( head, tail, inputVal );
    }
    findMinMax( head, &mx, &mn );
    cout << mx << ' ' << mn;
    return 0;
}

// Sample Input 0

// 2 4 1 5 3 6 -1
// Sample Output 0

// 6 1
// Sample Input 1

// 2 -1
// Sample Output 1

// 2 2