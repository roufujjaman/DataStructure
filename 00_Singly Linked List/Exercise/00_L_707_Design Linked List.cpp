class Node
{
public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node(val);
        size++;
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head = new_node;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node(val);
        size++;
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = tail->next;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        Node* new_node = new Node(val);
        size++;
        Node* current = head;
        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0)
        {
            if(head->next != NULL)
            {
                Node* delete_node = head;
                head = head->next;
                delete delete_node;
                size--;
                return;
            }
            else
            {
                head = NULL; // how to free heap for this
                tail = NULL; // how to free heap for this
                size--;
                return;
            }
        }
        Node* current = head;
        for (int i = 1; i < index; i++)
        {
            current = current->next;
        }
        if (current->next->next != NULL)
        {
            Node* delete_node = current->next;
            current->next = current->next->next;
            delete delete_node;
            size--;
        }
        else
        {
            Node* delete_node = current->next;
            tail = current;
            tail->next = NULL;
            delete delete_node;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */