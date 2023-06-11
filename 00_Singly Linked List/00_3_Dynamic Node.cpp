#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node *next;

        Node(int value)
        {
            this->value = value;
            this->next = NULL;
        }
};
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    //connecting nodes
    head->next = a;
    a->next = b;
    b->next = NULL;

    cout << head->value << endl; // (*head).value
    cout << head->next->value << endl; // (*(*head).next).value
    cout << head->next->next->value << endl; // (*(*(*head).next).next).value

    return 0;
}