class Node
{
    public:
        int val;
        int min;
        Node *next;
        Node *prev;
        Node( int val, int min )
        {
            this->val = val;
            this->min = min;
            this->next = NULL;
            this->prev = NULL;
        }
};
class MinStack {
public:
    Node *head = NULL;
    Node *tail = NULL;
    MinStack() {
        
    }
    
    void push(int val) {
        if( head == NULL )
        {
            Node *new_node = new Node( val, min( INT_MAX, val) );
            head = new_node;
            tail = new_node;
            return;
        }
        Node *new_node = new Node( val, min( val, tail->min ) );
        tail->next = new_node;
        new_node->prev = tail;
        tail = tail->next;
    }
    
    void pop() {
        Node *delete_node = tail;
        tail = tail->prev;
        delete delete_node;
        if( tail == NULL )
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }
    
    int top() {
        return tail->val;
    }
    
    int getMin() {
        return tail->min;
    }
};
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.