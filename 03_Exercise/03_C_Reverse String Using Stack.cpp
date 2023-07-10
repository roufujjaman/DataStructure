#include <bits/stdc++.h> 
void insertAtBottom( string &str, char val )
{
	if( str.empty() )
	{
		str.push_back( val );
		return;
	}
	char temp = str.back();
	str.pop_back();
	insertAtBottom( str, val );
	str.push_back( temp );
}
void reverse( string &str )
{
	if( str.empty() )
	{
		return;
	}
	char temp = str.back();
	str.pop_back();
	reverse( str );
	insertAtBottom( str, temp );
}
string kevinStackProblem(string &s)
{
	reverse( s );
	return s;
}
// #include <bits/stdc++.h> 
// string kevinStackProblem(string &s)
// {
// 	stack<char> obj;
// 	for( char c:s )
// 	{
// 		obj.push( c );
// 	}
// 	s.clear();
// 	while( !obj.empty() )
// 	{
// 		s.push_back( obj.top() );
// 		obj.pop();
// 	}
// 	return s;
// }