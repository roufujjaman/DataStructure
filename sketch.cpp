#include <bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        list<int> l;
        void push( int val )
        {
            l.push_back( val );
        }
        void pop()
        {
            l.pop_back();
        }
        int top()
        {
            return l.back();
        }
        int size()
        {
            return l.size();
        }
        bool empty()
        {
            if( l.size() == 0 ) return true;
            else return false;
        }
};
int main()
{   
    Stack myStack;
    int count, inputVal;
    cin >> count;
    for( int i = 0; i < count; i++)
    {   
        cin >> inputVal;
        myStack.push( inputVal );
    }
    while( !myStack.empty() )
    {
        cout << myStack.top() << ' ';
        myStack.pop();
    }
    return 0;
}