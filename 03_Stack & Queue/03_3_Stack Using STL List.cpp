#include <bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        list<int> v;
        void push( int val )
        {
            v.push_back( val );
        }
        void pop()
        {
            v.pop_back();
        }
        int top()
        {
            return v.back();
        }
        int size()
        {
            return v.size();
        }
        bool empty()
        {
            if( v.size() == 0 ) return true;
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
