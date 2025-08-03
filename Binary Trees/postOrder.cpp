/*

Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

Output: [4, 2, 7, 8, 5, 6, 3, 1]

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
	
	void postOrderTraversal(Node* root,vector<int> &ans){
		if(root==NULL){
			return;
		}
		postOrderTraversal(root->left,ans);
		postOrderTraversal(root->right,ans);
		ans.push_back(root->data);
		return;
	}
	
	vector<int> findPostorderTraversal(Node* root)
	{
		// Write your code here...
		vector<int> ans;
		// Write your code here...
		postOrderTraversal(root,ans);
		return ans;
	}
};
