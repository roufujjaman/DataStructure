#include <bits/stdc++.h> 
class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
bool isSpecialBinaryTree(BinaryTreeNode<int>* root)
{
    if( root->left == NULL && root->right == NULL ) return true;
    if( root->left == NULL || root->right == NULL ) return false;
    bool left = isSpecialBinaryTree( root->left );
    bool right = isSpecialBinaryTree( root->right );
    if( left == false || right == false ) return false;
    return true;
} 