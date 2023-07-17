/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void get_leaf( TreeNode * root, queue<int> * treeVals, int root_number )
    {
        if( root == NULL ) return;
        get_leaf( root->left, treeVals, root_number );
        get_leaf( root->right, treeVals, root_number );
        if( root_number == 1 )
        {
            if ( root->left == NULL && root->right == NULL ) treeVals->push( root->val );
        }
        else if( root_number == 2 )
        {
            if ( root->left == NULL && root->right == NULL && !treeVals->empty() )
            {
                if( root->val == treeVals->front() ) treeVals->pop();
                else treeVals->push( root->val );
            }
            else if( root->left == NULL && root->right == NULL && treeVals->empty() )
            {
                treeVals->push( root->val );
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> treeVals;
        get_leaf( root1, &treeVals, 1 );
        get_leaf( root2, &treeVals, 2 );
        return treeVals.empty();
    }
};class Solution {
public:
    void get_leaf( TreeNode * root, queue<int> * treeVals, int root_number )
    {
        if( root == NULL ) return;
        get_leaf( root->left, treeVals, root_number );
        get_leaf( root->right, treeVals, root_number );
        if( root_number == 1 )
        {
            if ( root->left == NULL && root->right == NULL ) treeVals->push( root->val );
        }
        else if( root_number == 2 )
        {
            if ( root->left == NULL && root->right == NULL && !treeVals->empty() )
            {
                if( root->val == treeVals->front() ) treeVals->pop();
                else treeVals->push( root->val );
            }
            else if( root->left == NULL && root->right == NULL && treeVals->empty() )
            {
                treeVals->push( root->val );
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> treeVals;
        get_leaf( root1, &treeVals, 1 );
        get_leaf( root2, &treeVals, 2 );
        return treeVals.empty();
    }
};