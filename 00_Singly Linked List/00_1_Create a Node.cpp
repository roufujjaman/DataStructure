#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node *next;
};
int main()
{
    Node a, b, c;
    a.value = 10;
    b.value = 20;
    c.value = 30;

    //connecting nodes
    a.next = &b;
    b.next = &c;
    c.next = NULL; // since c is the last element

    cout << a.value << endl;
    cout << (*a.next).value << endl;
    cout << (*(*a.next).next).value << endl;

    return 0;
}