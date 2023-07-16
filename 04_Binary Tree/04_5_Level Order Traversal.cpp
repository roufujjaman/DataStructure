#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node *left;
        Node *right;
        Node( int val )
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
void level_order( Node *root )
{
    queue<Node *> q;
    q.push( root );
    while ( !q.empty() )
    {
        // s t e p - 1
        Node * f = q.front();
        q.pop();

        // s t e p - 2
        cout << f->val << ' ';

        // s t e p - 3
        if(  f->left != NULL ) q.push( f->left );
        if( f->right != NULL ) q.push( f->right );
    }
    
}
int main()
{
    Node *root = new Node( 10 );
    Node *b = new Node( 20 );
    Node *c = new Node( 30 );
    Node *d = new Node( 40 );
    Node *e = new Node( 50 );
    Node *f = new Node( 60 );
    Node *g = new Node( 70 );
    Node *h = new Node( 80 );
    Node *i = new Node( 90 );
    Node *j = new Node( 100 );

    root->left = b;
    root->right = c;
    b->left = d;
    b->right = e;
    d->right = h;
    e->right = i;
    c->left = f;
    c->right = g;
    f->right = j;

    level_order( root );
    return 0;
}
