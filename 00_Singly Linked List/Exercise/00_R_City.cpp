#include <bits/stdc++.h>
using namespace std;
struct City
{
    string name_city;
    int area_km;
};
class Node
{
    public:
        City val;
        Node *next;

        Node(string name_city, int area_km)
        {
            this->val.name_city = name_city;
            this->val.area_km = area_km;
            this->next = NULL;
        }
};

int main() {
    Node *head = new Node("Dhaka", 316);
    Node *a = new Node("Chittogram", 155);
    Node *b = new Node("Khulna", 51);
    Node *c = new Node("Sylhet", 49);

    head->next = a;
    a->next = b;
    b->next = c;

    Node *temp = head;
    while( temp != NULL)
    {
        cout << temp->val.name_city << ' ' << temp->val.area_km << endl;
        temp = temp->next;
    }
    return 0;
}