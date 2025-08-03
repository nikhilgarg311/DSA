/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    
    bool solve(Node* root, int min , int max){
        if(root==NULL){
            return true;
        }
        
        if(root->data<min||root->data>max){
            return false;
        }
        
        bool left=solve(root->left,min,root->data);
        bool right=solve(root->right,root->data,max);
        
        if(left && right){
            return true;
        }
        
        return false;
        
    }
    
    
    bool isBST(Node* root) {
        // Your code here
        return solve(root, INT_MIN,INT_MAX);
        
    }
};