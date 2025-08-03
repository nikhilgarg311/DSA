//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    private:
    int findPosition(vector<int> &inorder,int element,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder,int &index,int inorderStart,int inorderEnd,int n){
        //base case
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        
        Node* root=new Node(preorder[index]);
        int position= findPosition(inorder,preorder[index],n);
        index++;
        root->left=solve(inorder,preorder,index,inorderStart,position-1,n);
        root->right=solve(inorder,preorder,index,position+1,inorderEnd,n);
        
        return root;
    }
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        Node* ans;
        int n=inorder.size();
        int index=0;
        ans=solve(inorder,preorder,index,0,n-1,n);
        return ans;
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends