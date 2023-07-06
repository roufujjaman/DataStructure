class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> objS, objT;
        for( char c:s )
        {
            if( c == '#' )
            {
                if( objS.empty() ) continue;
                objS.pop();
            }
            else 
            {
                objS.push( c );
            }
        }
        for( char c:t )
        {
            if( c == '#' )
            {
                if( objT.empty() ) continue;
                objT.pop();
            }
            else
            {
                objT.push( c );
            }
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