/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* succ=NULL;
        Node* pred=NULL;
        
        Node* temp=root;
        while(temp!=NULL && temp->data!=key){
            if(key<temp->data){
                succ=temp;
                temp=temp->left;
                
            }
            else{
                pred=temp;
                temp=temp->right;
            }
        }
        if(temp==NULL){
            ans.push_back(pred);
            ans.push_back(succ);
            return ans;
        }
        
        Node* leftMax=temp->left;
        Node* rightMin=temp->right;
        
        while(leftMax!=NULL){
            pred=leftMax;
            leftMax=leftMax->right;
        }
        
        while(rightMin!=NULL){
            succ=rightMin;
            rightMin=rightMin->left;
        }
        
        
        ans.push_back(pred);
        ans.push_back(succ);
        return ans;
        
    }
};