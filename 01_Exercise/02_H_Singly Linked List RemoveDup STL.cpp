#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> intList;
    int inputVal;
    while( true )
    {
        cin >> inputVal;
        if( inputVal == -1 ) break;
        intList.push_back( inputVal );
    } 
    intList.sort();
    intList.unique();
    for( int val: intList )
    {
        cout << val << ' ';
    }
    return 0;
}