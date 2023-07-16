#include<bits/stdc++.h>
using namespace std;
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
int maxHeight( TreeNode<int> *root, int *mx )
{
    if( root == NULL ) return 0;
    int left = maxHeight( root->left, mx );
    int right = maxHeight( root->right, mx );
    int diameter = left + right;
    *mx = max( diameter, *mx );
    return max( left, right ) + 1;

}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int mx = 0;
    maxHeight( root, &mx );
    return mx;
}

int main()
{
    ;
    return 0;
}