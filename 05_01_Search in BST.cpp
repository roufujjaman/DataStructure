#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node * left;
        Node * right;
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
        Node * parent = q.front();
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
bool find_node( Node * root, int query_val ) // O( height ) for good BST;
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
void level_order( Node * root )
{
    if( root == NULL ) return;
    queue<Node *> q;
    q.push( root );
    while( !q.empty() )
    {
        Node * parent = q.front();
        q.pop();

        cout << parent->val << ' ';

        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
}
int main()
{
    Node * root = input_tree(); // 10 5 15 2 6 12 16 -1 3 -1 -1 -1 -1 -1 -1 -1 -1
    level_order( root );
    find_node( root, 100 )? cout << "FOUND" : cout << "NOT FOUND";
    return 0;
}
