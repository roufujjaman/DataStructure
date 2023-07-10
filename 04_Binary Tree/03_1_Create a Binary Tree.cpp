#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *right;
        Node *left;
        Node( int val )
        {
            this->val = val;
            this->right = NULL;
            this->left = NULL;
        }
};
int main()
{
    Node *root = new Node( 10 );
    Node *a = new Node( 20 );
    Node *b = new Node( 30 );
    Node *c = new Node( 10 );
    Node *d = new Node( 10 );
    Node *e = new Node( 10 );
    Node *f = new Node( 10 );
    Node *g = new Node( 10 );
    Node *h = new Node( 10 );
    Node *i = new Node( 10 );

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;

    return 0;
}
