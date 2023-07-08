#include <bits/stdc++.h> 
class Node
{
    public:
        int data;
        Node *next;
        Node( int data )
        {
            this->data = data;
            this->next = NULL;
        }
};
class Queue {
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if( sz == 0 ) return true;
        else return false;
    }

    void enqueue(int data) {
        Node *new_node = new Node ( data );
        sz++;
        if( head == NULL )
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        tail = tail->next;
    }

    int dequeue() {
        if( head == NULL ) return -1;
        Node *delete_node = head;
        int data = head->data;
        head = head->next;
        delete delete_node;
        sz--;
        if( head == NULL ) tail = NULL;
        return data;
    }

    int front() {
        if( head == NULL ) return -1;
        else return head->data;
    }
};