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
Node * input_tree()
{
    int input_val;
    cin >> input_val;
    Node * root;
    if( input_val == -1 ) root = NULL;
    else root = new Node( input_val );
    queue<Node *> q;
    if( root != NULL ) q.push( root );
    while( !q.empty() )
    {
        Node *parent = q.front();
        q.pop();

        int input_val_l, input_val_r;
        cin >> input_val_l >> input_val_r;
        Node *new_node_l, *new_node_r;
        if( input_val_l == -1 ) new_node_l = NULL;
        else new_node_l = new Node( input_val_l );
        if( input_val_r == -1 ) new_node_r = NULL;
        else new_node_r = new Node( input_val_r );

        parent->left = new_node_l;
        parent->right = new_node_r;

        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    return root;
}
void LO_traverse( Node * root )
{
    if( root == NULL ) return;
    queue<Node *> q;
    q.push( root );
    while( !q.empty() )
    {
        Node *parent = q.front();
        q.pop();

        cout << parent->val << ' ';

        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
}
bool find_node( Node *root, int query_val )
{
    if( root == NULL ) return false;
    if( root->val == query_val ) return true;
    if( query_val < root->val ) 
    {
        return find_node( root->left, query_val );
    }
    else
    {
        return find_node( root->right, query_val );
    }
}
void insert_node( Node *&root, int input_val )
{
    if( root == NULL )
    {
        root = new Node( input_val );
        return;
    }
    if( input_val < root->val )
    {
        if( root->left == NULL ) root->left = new Node( input_val );
        else insert_node( root->left, input_val );
    }
    else
    {
        if( root->right == NULL ) root->right = new Node( input_val );
        else insert_node( root->right, input_val );
    }
}
int main()
{
    Node * root = NULL;
    insert_node( root, 10 );
    insert_node( root, 5 );
    insert_node( root, 15 );
    insert_node( root, 2 );
    insert_node( root, 6 );
    insert_node( root, 3 );
    insert_node( root, 16 );
    insert_node( root, 12 );
    LO_traverse( root );
    return 0;
}
