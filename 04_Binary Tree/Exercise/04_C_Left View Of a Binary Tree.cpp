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
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> returnVal;
    bool levels[3001] = {true}; 
    queue<pair<TreeNode<int> *, int>> q;
    if( root != NULL ) q.push( {root, 1 } );
    while( !q.empty() )
    {
        TreeNode<int> * parent = q.front().first;
        int level = q.front().second;
        q.pop();

        if( levels[level] == false )
        {
            returnVal.push_back( parent->data );
            levels[level] = true;
        }

        if( parent->left != NULL ) q.push( { parent->left, level + 1 } );
        if( parent->right != NULL ) q.push( { parent->right, level + 1 });
    }
    return returnVal;
}