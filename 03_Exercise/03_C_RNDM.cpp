#include<bits/stdc++.h>
using namespace std;
void insertAtPosition( queue<int> &obj, int ele, int pos, int current_pos )
{
    if( obj.empty() ) return;
    int current = obj.front();
    current_pos++;
    obj.pop();
    insertAtPosition( obj, ele, pos, current_pos );
    if( pos == current_pos )
    {
        obj.push( ele );
    }
    obj.push( current );
}
int main()
{
    queue<int> obj;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        obj.push( inputVal );
    }
    insertAtPosition( obj, 100, 3, 1 );
    while( !obj.empty() )
    {
        cout << obj.front() << ' ';
        obj.pop();
    }
    cout << obj.front();
    return 0;
}