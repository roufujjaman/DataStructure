#include <bits/stdc++.h>

using namespace std;
class Node
{
    public:
        int val;
        int level;
        Node *left;
        Node *right;
        Node( int val, int level )
        {
            this->val = val;
            this->level = level;
            this->left = NULL;
            this->right = NULL;
        }
};
int main()
{
    // Write your code here
    Node * root;
    int inputVal;
    cin >> inputVal;
    if( inputVal == -1 ) root = NULL;
    else root = new Node( inputVal, 0 );
    queue<Node *> q;
    if( root != NULL ) q.push( root );
    while( !q.empty() )
    {
        Node * parent = q.front();
        int level = q.front()->level;
        q.pop();
        
        int inputValLeft, inputValRight;
        cin >> inputValLeft >> inputValRight;
        
        Node * new_node_l, * new_node_r;
        if( inputValLeft == -1 ) new_node_l = NULL;
        else new_node_l = new Node( inputValLeft, level + 1);
        
        if( inputValRight == -1 ) new_node_r = NULL;
        else new_node_r = new Node( inputValRight, level + 1 );
        
        parent->left = new_node_l;
        parent->right = new_node_r;
        
        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    int level_query;
    bool found = false;
    cin >> level_query;
    q.push( root );
    while( !q.empty() )
    {
        Node * parent = q.front();
        q.pop();
        
        if( parent->level == level_query )
        {
            cout << parent->val << ' ';
            found = true;
        }
        if( parent->level == level_query + 1 )
        {
            break;
        }
        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    if( found != true ) cout << "Invalid";
    return 0;
}