#include <bits/stdc++.h> 
template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int nodeLevel(TreeNode<int>* root, int searchedValue)
{
    queue<pair<TreeNode<int>*, int>> q;
    q.push( { root, 1 } );
    while( !q.empty() )
    {
        TreeNode<int>* parent = q.front().first;
        int level = q.front().second;
        q.pop();

        if( parent->val == searchedValue ) return level;

        if( parent->left != NULL ) q.push( {parent->left, level + 1 } );
        if( parent->right != NULL ) q.push( {parent->right, level + 1 } );
    }
}