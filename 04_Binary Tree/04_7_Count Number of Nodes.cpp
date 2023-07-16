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
void level_order( Node *root )
{
    if( root == NULL ) return;
    queue<Node *> q;
    q.push( root );
    while( !q.empty() )
    {
        Node * current = q.front();
        q.pop();

        cout << current->val << ' ';

        if( current->left != NULL ) q.push( current->left );
        if( current->right != NULL ) q.push( current->right );
    }
}
Node *input_tree()
{
    int inputVal;
    cin >> inputVal;
    Node *root;
    if( inputVal == -1 ) root = NULL;
    else root = new Node( inputVal );
    queue<Node *> q;
    q.push( root );
    while ( !q.empty() )
    {
        // s t e p - 1
        Node *parent  = q.front();
        q.pop();
        
        // s t e p - 2
        int leftInputVal, rightInputVal;
        cin >> leftInputVal >> rightInputVal;
        
        Node *new_node_left, *new_node_right;
        if( leftInputVal == -1 ) new_node_left = NULL;
        else new_node_left = new Node( leftInputVal );
        
        if( rightInputVal == -1 ) new_node_right = NULL;
        else new_node_right = new Node( rightInputVal );

        parent->left = new_node_left;
        parent->right = new_node_right;

        // s t e p - 3
        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    
    return root;
}
int count_node( Node * root )
{
    if( root == NULL ) return 0;
    int count_left = count_node( root->left );
    int count_right = count_node( root->right );
    return 1 + count_left + count_right;
}
int main()
{
    Node *root = input_tree();
    level_order( root );
    cout << endl;
    cout << count_node( root ); // number of nodes;

    return 0;
}
