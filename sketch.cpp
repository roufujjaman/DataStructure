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
            this->left = left;
            this->right = right;
        }
};
Node* input()
{
    int input_val;
    cin >> input_val;
    Node* root;
    if(input_val == -1)
    {
        root = NULL;
        return root;
    }
    else root = new Node(input_val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* parent = q.front();
        q.pop();

        int input_val_left, input_val_right;
        cin >> input_val_right >> input_val_left;
        if(input_val_left == -1) parent->left = NULL;
        else parent->left = new Node(input_val_left);
        if(input_val_right == -1) parent->right = NULL;
        else parent->right = new Node(input_val_right);

        if(parent->left != NULL) q.push(parent->left);
        if(parent->right != NULL) q.push(parent->right);
    }
    return root;
}
void po_traverse(Node* root)
{
    if(root == NULL) return;
    po_traverse(root->left);
    po_traverse(root->right);
    cout << root->val << ' ';
}
void lo_traverse(Node* root)
{
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
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
    if(left>right) return NULL;
    int mid = (left + right ) / 2;
    Node* root = new Node(arr[mid]);
    Node* left_node = convert(arr, left, mid - 1);
    Node* right_node = convert(arr, mid + 1, right);
    root->left = left_node;
    root->right = right_node; 
    return root;
}
int main()
{
    int arr[10] = {24, 31, 35, 44, 60, 100, 120, 130, 150, 155};
    Node* root = convert(arr, 0, 9);
    lo_traverse(root);
    return 0;
}