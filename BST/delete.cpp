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
    int getMin(TreeNode* root){
        TreeNode* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }

        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {  
        if(root==NULL){
            return root;
        }
        
        if(root->val==key){

            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp= root->left;
                delete root;
                return temp;
            }

            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp= root->right;
                delete root;
                return temp;
            }

            if(root->left!=NULL && root->right!=NULL){
                int mini = getMin(root->right);
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                return root;

                // int maxi = getMax(root->left);
                // root->val=maxi;
                // root->right=deleteNode(root->left,maxi);
                // return root;
            }
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
            return root;
        }
        else{
            root->right= deleteNode(root->right,key);
            return root;
        }
        return root;
    }
};