/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    void inOrderTraversal(Node* root, vector<int> &ans){
        
        if(root==NULL){
            return;
        }
        
        inOrderTraversal(root->left,ans);
        ans.push_back(root->data);
        inOrderTraversal(root->right,ans);
        
        return;
        
    }
    
    int kthSmallest(Node *root, int k) {
        // add code here.
        vector<int> ans;
        inOrderTraversal(root,ans);
        if(k>ans.size()){
            return -1;
        }
        return ans[k-1];
        
    }
};