#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val)
        {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};
void insert_node(Node* & root, int insert_val)
{
    if(root == NULL)
    {
        root = new Node(insert_val);
        return;
    }
    if(insert_val < root->val)
    {
        if(root->left == NULL) root->left = new Node(insert_val);
        else insert_node(root->left, insert_val);
    }
    else if(insert_val > root->val)
    {
        if(root->right == NULL) root->right = new Node(insert_val);
        else insert_node(root->right, insert_val);
    }
}
void lo_traversal( Node* root )
{
    if( root == NULL ) return;
    queue<Node*> q;
    q.push( root );
    while( !q.empty() )
    {
        Node* parent = q.front();
        q.pop();

        cout << parent->val << ' ';

        if(parent->left != NULL) q.push(parent->left);
        if(parent->right != NULL) q.push(parent->right);
    }
}
Node* convert(int arr[], int left, int right)
{
    if( left > right ) return NULL;
    int mid = (left + right) / 2;
    Node* root = new Node(arr[mid]);
    Node* new_node_left = convert(arr, left, mid - 1);
    Node* new_node_right = convert(arr, mid + 1, right);
    root->left = new_node_left;
    root->right = new_node_right;
    return root;

}
int main()
{
    int arr[9] = {1, 3, 5, 6, 7, 21, 26, 31, 40};
    Node* root = convert(arr, 0, 8);    
    lo_traversal(root);
    return 0;
}