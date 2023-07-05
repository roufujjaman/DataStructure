#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arr[3] = {0};
    bool isValid(string s) {
        for( char c:s )
        {
            if( c == '(') arr[0]++;
            else if( c == ')' ) arr[0]--;
            if( c == '{') arr[0]++;
            else if( c == '}' ) arr[0]--;
            if( c == '[') arr[0]++;
            else if( c == ']' ) arr[0]--;
        }
        if( arr[0] == 0 && arr[1] == 0 && arr[2] == 0 ) return true;
        else return false;
    }
};
int main()
{
    Solution obj;
    cout << obj.isValid( "(]" );
    return 0;
}