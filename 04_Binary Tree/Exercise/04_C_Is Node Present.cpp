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
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if( root == NULL ) return false;
    if( root->data == x ) return true;
    bool left = isNodePresent( root->left );
    bool right = isNodePresent( root->right );
    return ( left || right );
}