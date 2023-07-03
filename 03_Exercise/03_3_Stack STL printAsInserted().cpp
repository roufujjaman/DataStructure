#include<bits/stdc++.h>
using namespace std;
void printAsInserted( stack<int> obj )
{
    stack<int> obj_new;
    while ( !obj.empty() )
    {
        obj_new.push( obj.top() );
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
    stack<int> obj;
    int count, inputVal;
    cin >> count;
    for( int i = 0; i < count; i++ )
    {   
        cin >> inputVal;
        obj.push( inputVal );
    }
    printAsInserted( obj );
    return 0;
}
