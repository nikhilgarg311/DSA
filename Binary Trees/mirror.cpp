void mirror(Node* node) {
        // code here
        if(node==NULL){
            return;
        }
        
        mirror(node->left);
        mirror(node->right);
        Node* temp= node->left;
        node->left=node->right;
        node->right=temp;
        return;
    }