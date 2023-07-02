#include <bits/stdc++.h>
using namespace std;
class Stack
{
    public:
        vector<int> v;
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
    myStack.push( 100 );
    myStack.push( 200 );
    cout << myStack.top() << endl;
    if( !myStack.empty() ) myStack.pop(); 
    cout << myStack.top() << endl;
    if( !myStack.empty() ) myStack.pop(); 
    myStack.empty()? cout << "-EMPTY-" << endl : cout << myStack.top() << endl;
    return 0;
}
