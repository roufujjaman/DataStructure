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
void lo_traverse(Node* root)
{
    if (root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();

        cout << parent->val << ' ';

        if (parent->left != NULL) q.push(parent->left);
        if (parent->right != NULL) q.push( parent->right);
    }
}
Node* convert(int arr[], int left, int right)
{
    if(left > right) return NULL;
    int mid = (left + right) / 2; 
    Node* root = new Node(arr[mid]);
    Node* left_root = convert(arr, left, mid - 1);
    Node* right_root = convert(arr, mid + 1, right );
    root->left = left_root;
    root->right = right_root;
    return root;
}
int main()
{
    int arr[10] = {2, 5, 8, 12, 15, 18};
    Node* root = convert( arr, 0, 5 );
    lo_traverse( root );
    return 0;
}
