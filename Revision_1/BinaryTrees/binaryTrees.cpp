void inOrderTraversal(Node* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    inOrderTraversal(root->left,res);
    res.push_back(root->data);
    inOrderTraversal(root->right,res);
    return;
}
// Function to return a list containing the inorder traversal of the tree.
vector<int> inOrder(Node* root) {
    // Your code here
    vector<int> res;
    inOrderTraversal(root,res);
    return res;
}

void preOrderTraversal(Node* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    res.push_back(root->data);
    preOrderTraversal(root->left,res);
    preOrderTraversal(root->right,res);
    return;
}
// Function to return a list containing the preorder traversal of the tree.
vector<int> preorder(Node* root) {
    // write code here
    vector<int> res;
    preOrderTraversal(root,res);
    return res;
}

void postOrderTraversal(Node* root, vector<int> &res){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left,res);
    postOrderTraversal(root->right,res);
    res.push_back(root->data);
    return;
}

vector<int> postOrder(Node* root) {
    // Your code here
    vector<int> res;
    postOrderTraversal(root,res);
    return res;
}

vector<vector<int>> levelOrder(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    vector< vector<int> > res;
    vector<int> elements;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        
        if(temp==NULL){ //level finish
            res.push_back(elements);
            elements.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            elements.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
    return res;
}

vector<int> reverseLevelOrder(Node *root) {
    // code here
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    //vector< vector<int> > res;
    vector<int> elements;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){ //level finish
            continue;
        }
        else{
            elements.push_back(temp->data);
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
        
    }
    reverse(elements.begin(),elements.end());
    return elements;
}

int height(Node* node) {
    if(node==NULL){
        return -1;
    }
    // code here
    int leftHeight=height(node->left);
    int rightHeight=height(node->right);
    return (1+max(leftHeight,rightHeight));
}

///////////////-----------------------///////////////////////
int diameterHeight(Node* node, int &res){
    if(node==NULL){
        return 0;
    }
    
    int leftHeight=diameterHeight(node->left,res);
    int rightHeight=diameterHeight(node->right,res);
    res=max(res,leftHeight+rightHeight);
    return 1+max(leftHeight,rightHeight);
}

int diameter(Node* root) {
    // Your code here 
    int res=0;
    diameterHeight(root,res);
    return res;
    
}
////////////////////----------------/////////////////////////

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

vector<int> rightView(Node *root) {
    // Your Code here
        // code here
    vector<int> res;
    if(root==NULL){
        return res;
    }
    //node,lvl
    queue< pair<Node*,int> > q;
    q.push(make_pair(root,0));
    //lvl,node->data
    map<int,int> m;
    
    while(!q.empty()){
        pair<Node*,int> front=q.front();
        q.pop();
        int lvl=front.second;
        Node* temp= front.first;
        m[lvl]=temp->data;
        if(temp->left){
            q.push(make_pair(temp->left,lvl+1));
        }
        if(temp->right){
            q.push(make_pair(temp->right,lvl+1));
        }
    }
    
    for(auto i:m){
        res.push_back(i.second);
    }
    return res;
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    // code here
    if(root==NULL){
        return ans;
    }
    //node,level
    queue<pair<Node*,int> > q;
    //level,node->data
    map<int,int> m;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> front=q.front();
        int lvl=front.second;
        Node* temp= front.first;
        q.pop();
        if(m.find(lvl)==m.end()){
            m[lvl]=temp->data;
        }
        if(temp->left){
            q.push(make_pair(temp->left,lvl+1));
        }
        if(temp->right){
            q.push(make_pair(temp->right,lvl+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> topView(Node *root) {
    // code here
    vector<int> ans;
    // code here
    if(root==NULL){
        return ans;
    }
    //node,hd
    queue<pair<Node*,int> > q;
    //hd,node->data
    map<int,int> m;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> front=q.front();
        int hd=front.second;
        Node* temp= front.first;
        q.pop();
        if(m.find(hd)==m.end()){
            m[hd]=temp->data;
        }
        if(temp->left){
            q.push(make_pair(temp->left,hd-1));
        }
        if(temp->right){
            q.push(make_pair(temp->right,hd+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node *root) {
    // code here
    vector<int> ans;
    // code here
    if(root==NULL){
        return ans;
    }
    //node,hd
    queue<pair<Node*,int> > q;
    //hd,node->data
    map<int,int> m;
    q.push(make_pair(root,0));
    
    while(!q.empty()){
        pair<Node*,int> front=q.front();
        int hd=front.second;
        Node* temp= front.first;
        q.pop();
        m[hd]=temp->data;
        if(temp->left){
            q.push(make_pair(temp->left,hd-1));
        }
        if(temp->right){
            q.push(make_pair(temp->right,hd+1));
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    return ans;
}
////////////////--------------------////////////////////////
pair<bool,int> isBalancedFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    pair<bool,int> left= isBalancedFast(root->left);
    pair<bool,int> right= isBalancedFast(root->right);
    pair<bool,int> ans;
    int leftHeight=left.second;
    int rightHeight=right.second;
    ans.second=max(leftHeight,rightHeight)+1;
    bool diff= (abs(leftHeight-rightHeight)<=1);
    if(left.first && right.first && diff ){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
}
bool isBalanced(Node* root) {
    // Code here
    pair<bool,int> ans=isBalancedFast(root);
    return ans.first;
}

//////////////////------------------------///////////////////////
void levelOrderTraversal(Node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    bool flagLeftToRight=true;
    while(!q.empty()){
        int size=q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            Node* front= q.front();
            q.pop();
            int index=flagLeftToRight? i:size-i-1;
            temp[index]=front->data;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        flagLeftToRight=!flagLeftToRight;
        for(auto i:temp){
            ans.push_back(i);
        }

    }
}
// Function to store the zig zag order traversal of tree in a list.
vector<int> zigZagTraversal(Node* root) {
    // Code here
    vector<int> ans;
    levelOrderTraversal(root,ans);
    return ans;
}

//////////////-------------------/////////////////////////
pair<bool,int> sumTree(Node* root){
    //base case
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    
    if(root->right==NULL && root->left==NULL){
        pair<bool,int> p= make_pair(true,root->data);
        return p;
    }
    //recursive call
    
    pair<bool,int> left=sumTree(root->left);
    pair<bool,int> right=sumTree(root->right);
    
    bool isSum=false;
    if((root->data)==(left.second + right.second)){
        isSum=true;
    }
    
    pair<bool,int> ans;
    ans.second=2*root->data;
    if(left.first && right.first && isSum){
        ans.first=true;
    }
    else{
        ans.first=false;
    }
    return ans;
    
}
bool isSumTree(Node* root) {
    // Your code here
    pair<bool,int> ans=sumTree(root);
    return ans.first;
}
/////////////--------------------//////////////////

int findPosition(vector<int> inorder,int num){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==num){
            return i;
        }
    }
}

Node* solve(vector<int> &inorder, vector<int> &preorder, int inorderStart, int inorderEnd,int &index,int n){
    if(index>=n||inorderStart>inorderEnd){
        return NULL;
    }
    Node* root= new Node(preorder[index]);
    int position= findPosition(inorder,preorder[index]);
    index++;
    root->left=solve(inorder,preorder,inorderStart,position-1,index,n);
    root->right=solve(inorder,preorder,position+1,inorderEnd,index,n);
    
    return root;
}
// Function to build the tree from given inorder and preorder traversals
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    // code here
    int inorderStart=0;
    int n=inorder.size();
    int inorderEnd=n-1;
    int index=0;
    return solve(inorder,preorder,inorderStart,inorderEnd,index,n);
}

///////////////////////----------------------------/////////////////////////

int findPosition(vector<int> inorder,int num){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==num){
            return i;
        }
    }
}

Node* solve(vector<int> &inorder, vector<int> &postorder, int inorderStart, int inorderEnd,int &index,int n){
    if(index<0||inorderStart>inorderEnd){
        return NULL;
    }
    Node* root= new Node(postorder[index]);
    int position= findPosition(inorder,postorder[index]);
    index--;
    root->right=solve(inorder,postorder,position+1,inorderEnd,index,n);
    root->left=solve(inorder,postorder,inorderStart,position-1,index,n);
    
    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node* buildTree(vector<int> inorder, vector<int> postorder) {
    // code here
    int inorderStart=0;
    int n=inorder.size();
    int inorderEnd=n-1;
    int index=n-1;
    return solve(inorder,postorder,inorderStart,inorderEnd,index,n);
}

/////////----------------------------------///////////////////