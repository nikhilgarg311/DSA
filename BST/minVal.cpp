class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        Node* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
            
        }
        return temp->data;
    }
};