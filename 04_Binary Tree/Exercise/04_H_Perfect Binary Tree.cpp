#include <bits/stdc++.h>

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
int totalNodes( Node * root )
{
    if( root == NULL ) return 0;
    int left = totalNodes( root->left );
    int right = totalNodes( root->right );
    return 1 + left + right;
}
int maxHeight( Node * root )
{
    if( root == NULL ) return 0;
    int left = maxHeight( root->left );
    int right = maxHeight( root->right );
    return 1 + max( left, right );
}
int main()
{
    // Write your code here
    Node * root;
    int inputVal;
    cin >> inputVal;
    if( inputVal == -1 ) root = NULL;
    else root = new Node( inputVal );
    queue<Node *> q;
    if( root != NULL ) q.push( root );
    while( !q.empty() )
    {
        Node * parent = q.front();
        q.pop();
        
        int inputValLeft, inputValRight;
        cin >> inputValLeft >> inputValRight;
        
        Node * new_node_l, * new_node_r;
        if( inputValLeft == -1 ) new_node_l = NULL;
        else new_node_l = new Node( inputValLeft );
        
        if( inputValRight == -1 ) new_node_r = NULL;
        else new_node_r = new Node( inputValRight );
        
        parent->left = new_node_l;
        parent->right = new_node_r;
        
        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    int total_nodes = totalNodes( root );
    int max_height = maxHeight( root );
    if( total_nodes == pow( 2, max_height ) - 1 ) cout << "YES";
    else cout << "NO";
    return 0;
}