class Solution {
public:
    stack<char> objS, objT;
    bool backspaceCompare(string s, string t) {
        for( char C:s )
        {
            if( C == '#' )
            {
                if( objS.empty() ) continue;
                objS.pop();
                continue;
            }
            objS.push( C );
        }
        for( char C:t )
        {
            if( C == '#' )
            {
                if( objT.empty() ) continue;
                objT.pop();
                continue;
            }
            objT.push( C );
        }
        if( objS.size() != objT.size() ) return false;
        while( !objS.empty() )
        {
            if( objS.top() != objT.top() ) return false;
            objS.pop();
            objT.pop();
        }
        return true;
    }
};

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".