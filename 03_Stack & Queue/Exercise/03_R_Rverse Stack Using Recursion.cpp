#include<bits/stdc++.h>
using namespace std;
// class Node
// {
//     public:
//         int val;
//         Node *next;
//         Node *prev;
//         Node( int val )
//         {
//             this->val = val;
//             this->next = NULL;
//             this->next = NULL;
//         }
// };
// class Stack
// {
//     private:
//         Node *head = NULL;
//         Node *tail = NULL;
//         int sz = 0; 
//     public:
//         void push( int val )
//         {
//             Node *new_node = new Node( val );
//             sz++;
//             if( head == NULL )
//             {
//                 head = new_node;
//                 tail = new_node;
//                 return;
//             }
//             tail->next = new_node;
//             new_node->prev = tail;
//             tail = tail->next;
//         }
//         void pop()
//         {
//             Node *delete_node = tail;
//             tail = tail->prev;
//             delete delete_node;
//             sz--;
//             if( tail == NULL )
//             {
//                 head = NULL;
//                 return;
//             }
//             tail->next = NULL;
//         }
//         int top()
//         {
//             return tail->val;
//         }
//         int size()
//         {
//             return sz;
//         }
//         bool empty()
//         {
//             if( sz == 0 ) return true;
//             else return false;
//         }
// };
void insertAtBottom( stack<int> &obj, int ele )
{
    if ( obj.empty() )
    {
        obj.push( ele );
        return;
    }
    int top_ele = obj.top();
    obj.pop();
    insertAtBottom( obj, ele );
    obj.push( top_ele );
} 
void reverse( stack<int> &obj )
{
    if( obj.empty() ) return;

    int ele = obj.top();
    obj.pop();
    reverse( obj );
    insertAtBottom( obj, ele );
}
int main()
{
    stack<int> obj;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        obj.push( inputVal );
    }
    reverse( obj );
    while( !obj.empty() )
    {
        cout << obj.top() << ' ';
        obj.pop();
    }
    return 0;
}
