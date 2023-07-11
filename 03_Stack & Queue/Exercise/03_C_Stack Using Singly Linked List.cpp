class Stack
{
private:
    Node *head = NULL;
    int sz = 0;
public:
    Stack()
    {
        //Write your code here 
    }

    int getSize()
    {
        return sz;
    }

    bool isEmpty()
    {
        if( sz == 0 ) return true;
        else return false;  
    }

    void push(int data)
    {
        Node *new_node = new Node( data );
        sz++;
        if( head == NULL )
        {
            head = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }

    void pop()
    {
        if( head == NULL )
        {
            return;
        }
        Node *delete_node = head;
        head = head->next;
        delete delete_node;
        sz--;
    }

    int getTop()
    {
        if( sz == 0 ) return -1;
        else return head->data;
    }
};