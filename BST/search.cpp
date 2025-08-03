// Function to search a node in BST.
bool search(Node* root, int x) {
    // Your code here
    if(root->data==x){
        return true;
        
    }
    
    if(x<root->data && root->left!=NULL){
    
        return search(root->left,x);
    }
    else if(x>root->data && root->right!=NULL){
        return search(root->right,x);
    }
    return false;
    
    
}