#include<bits/stdc++.h>
using namespace std;
int main()
{
    // list<int> myList;
    // list<int> myList( 10 );
    // list<int> myList( 10, 5 ); //>> size - 10, all initialized with - 5;
    // cout << myList.front(); //>> 5
    // cout << myList.back(); //>> 5
    list<int> myListCopy( a, a + 5 );
    
    int a[5] = {100, 200, 300, 400 , 500};
    
    for( auto it = myListCopy.begin(); it != myListCopy.end(); it++ )
    {
        cout << *it << ' ';
    }
    cout << endl << myListCopy.size();
    return 0;

}
