#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> myList = {10, 20, 30, 40, 50};
    // cout << myList.max_size() << endl;
    // myList.clear();
    myList.resize( 2 ); // 10 20
    myList.resize( 5, 100 ); // 10 20 100 100 100
    cout << myList.size() << endl;
    for( int val: myList )
    {
        cout << val << ' ';
    }
    cout << endl << myList.empty(); // false - 0;
    return 0;
}
