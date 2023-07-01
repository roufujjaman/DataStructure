#include<bits/stdc++.h>
using namespace std;
class myStack
{
    public:
        vector<int> arr;
        int sz = 0;
        void push( int val )
        {
            arr.push_back( val );
            sz++;
        }
        void pop()
        {
            arr.pop_back();
            sz--;
        }
        int top()
        {
            return arr.back();
        }
        int size()
        {
            return sz;
        }
        bool empty()
        {
            sz == 0 ? true : false;
        }
};
int main()
{
    myStack arr;
    arr.push(100);
    cout << arr.size() << endl;
    arr.pop();
    arr.pop();
    return 0;
}