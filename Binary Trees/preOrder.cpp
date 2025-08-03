/*

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input:
		   1
		 /   \
		/	  \
	   2	   3
	  /		  / \
	 /	  	 /	 \
	4		5	  6
		   / \
		  /   \
		 7	   8

Output: [1, 2, 4, 3, 5, 7, 8, 6]

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/

	void preOrderTraversal(Node* root,vector<int> &ans){
		if(root==NULL){
			return;
		}
		ans.push_back(root->data);
		preOrderTraversal(root->left,ans);
		preOrderTraversal(root->right,ans);
		return;
	}
	vector<int> findPreorderTraversal(Node* root)
	{
		vector<int> ans;
		// Write your code here...
		preOrderTraversal(root,ans);
		return ans;
	}
};
