#include <bits/stdc++.h>
template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
vector<int> reverseLevelOrder(TreeNode<int> *root){
    // Write your code here.
    vector<int> returnVal;
    queue<TreeNode<int> *> q;
    if( root != NULL ) q.push( root );
    while( !q.empty() )
    {
        TreeNode<int> * parent = q.front();
        q.pop();

        returnVal.push_back( parent->val );

        if( parent->left != NULL ) q.push( parent->left );
        if( parent->right != NULL ) q.push( parent->right );
    }
    reverse( returnVal.begin(), returnVal.end() );
    return returnVal;
}