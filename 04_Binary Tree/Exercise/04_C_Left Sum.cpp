#include <bits/stdc++.h> 

class BinaryTreeNode 
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
}
long long leftSum(BinaryTreeNode<int> *root)
{
	long long int sum = 0;
	queue<BinaryTreeNode<int> *> q;
	q.push( root );
	while( !q.empty())
	{
		BinaryTreeNode<int> * parent = q.front();
		q.pop();

		if( parent->left != NULL ) sum += parent->left->data;

		if( parent->left != NULL ) q.push( parent->left );
		if( parent->right != NULL ) q.push( parent->right );
	}
	return sum;
}