#include<bits/stdc++.h>
using namespace std;
void printReverse( queue<int> obj )
{
    stack<int> obj_new;
    while ( !obj.empty() )
    {
        obj_new.push( obj.front() );
        obj.pop();
    }
    while( !obj_new.empty() )
    {
        cout << obj_new.top() << ' ';
        obj_new.pop();
    }
    cout << endl;
}
int main()
{
    queue<int> obj;
    int count, inputVal;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {   
        cin >> inputVal;
        obj.push( inputVal );
    }
    printReverse( obj );
    return 0;
}
