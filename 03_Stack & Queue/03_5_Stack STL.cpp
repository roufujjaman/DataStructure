#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> obj;
    int count, inputVal;
    cin >> count;
    for ( int i = 0; i < count; i++ )
    {
        cin >> inputVal;
        obj.push( inputVal );
    }
    cout << obj.size() << endl;
    while ( !obj.empty() )
    {
        cout << obj.top() << endl;
        obj.pop();
    }
    return 0;
}