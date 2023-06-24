#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList= { 10, 20, 30 };
    // list<int> newList;
    // // newList = myList;
    // newList.assign( myList.begin(), myList.end() ); //>> 10 20 30

    myList.push_back( 50 ); // 10 20 30 50
    myList.push_front( 0 ); // 0 10 20 30 50
    // myList.pop_back();
    // myList.pop_front();
    myList.insert( next( myList.begin(), 4), 40 ); // 0 10 20 30 40 50
    myList.erase( myList.begin() ); // 10 20 30 40 50
    myList.erase( next( myList.begin(), 2) ); // 10 20 40 50
    myList.insert( myList.end(), { 60, 70, 80, 90, 100 } ); 
    myList.insert( next( myList.begin(), 2 ), 30 );
    replace( myList.begin(), myList.end(), 50, 5); // 10 20 30 40 5 60 70 80 90 100
    for( int val: myList )
    {
        cout << val << ' ';
    }
    cout << endl;

    int queryVal;
    cin >> queryVal;
    auto it = find( myList.begin(), myList.end(), queryVal );
    if ( it == myList.end() )
    {
        cout << "NOT FOUND";
    }
    else
    {
        cout << "FOUND";
    }
    return 0;
}
