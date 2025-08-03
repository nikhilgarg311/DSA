class Solution {
  public:
    int maxValue(Node* root) {
        // Code here
        Node* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
            
        }
        return temp->data;
    }
};