/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  
      void inOrderTraversal(Node* root, vector<int> &ans){
        
        if(root==NULL){
            return;
        }
        
        inOrderTraversal(root->left,ans);
        ans.push_back(root->data);
        inOrderTraversal(root->right,ans);
        
        return;
        
    }
    
    int kthLargest(Node *root, int k) {
        // Your code here
        vector<int> ans;
        inOrderTraversal(root,ans);
        int n=ans.size();
        if(k>n){
            return -1;
        }
        return ans[n-k];
        
    }
};