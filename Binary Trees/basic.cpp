#include<iostream>
using namespace std;

class node{

public:
    int data;
    node *right;
    node *left;

    node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

 node* buildTree(node* root){

    cout<<"Enter data:"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root= new node(data);
    cout<<"Enter data to be inserted in left of"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data to be inserted in right of"<<data<<endl;
    root->right=buildTree(root->right);
    return root;
 }
 
 int main(){
    node* root=NULL;
    root=buildTree(root);
 }