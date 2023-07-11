#include <bits/stdc++.h> 
class Val
{
	public:
		int val;
		int min;
};
class minStack
{
	stack<Val> stk;
	public:
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if( stk.empty() )
			{
				stk.push( { num, min( num, INT_MAX )} );
			}
			else
			{
				stk.push( { num, min( num, stk.top().min ) } );
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if( stk.empty() ) return -1;
			else
			{
				int val = stk.top().val;
				stk.pop();
				return val;
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if( stk.empty() ) return -1;
			else return stk.top().val;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if( stk.empty() ) return -1;
			else return stk.top().min;
		}
};