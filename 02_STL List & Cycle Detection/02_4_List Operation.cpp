#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = { 10, 15, 10, 150, 75, 1, 12, 10, 21, 15, 61, 15};
    myList.remove( 10 );
    myList.sort( greater<int>() ); //150 75 61 21 15 15 15 12 1
    myList.unique(); //150 75 61 21 15 12 1 
    myList.reverse(); //1 12 15 21 61 75 150 
    for( int val: myList )
    {
        cout << val << ' ';
    }
    return 0;
}
