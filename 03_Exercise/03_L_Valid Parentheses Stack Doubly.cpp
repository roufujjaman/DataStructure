class Node
{
    public:
        char val;
        Node *next;
        Node *prev;
        Node( char val )
        {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
};
class Stack
{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int stack_size = 0;
        void push( char val )
        {
            Node *new_node = new Node( val );
            stack_size++;
            if( head == NULL )
            {
                head = new_node;
                tail = new_node;
                return;
            }
            tail->next = new_node;
            new_node->prev = tail;
            tail = tail->next;
        }
        void pop()
        {
            Node *delete_node = tail;
            tail = tail->prev;
            delete delete_node;
            stack_size--;
            if( tail == NULL )
            {
                head = NULL;
                return;
            }
            tail->next = NULL;
        }
        char top()
        {
            return tail->val;
        }
        bool empty()
        {
            if( stack_size == 0 ) return true;
            else return false;
        }
};
class Solution {
public:
    bool isValid(string s) {
        Stack obj;
        int i = 0;
        for( char c:s )
        {
            if( c == '(' || c == '{' || c == '[' )
            {
                obj.push( c );
            }
            else if( c == ')' || c == '}' || c == ']' )
            {
                if( obj.empty() ) return false;
                else if( c == ')' && obj.top() == '(' ) obj.pop();
                else if( c == '}' && obj.top() == '{' ) obj.pop();
                else if( c == ']' && obj.top() == '[' ) obj.pop();
                else return false;
            }
        }
        if( obj.empty() ) return true;
        else return false;
    }
};
// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false