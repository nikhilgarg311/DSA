#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data =data;
        this->next=NULL;
    }
};
// Function to remove duplicates from sorted linked list.
Node* removeDuplicates(Node* &head) {
if(head==NULL){
    return NULL;
}
struct Node* temp=head;
while(temp->next!=NULL){
    if(temp->data==temp->next->data){
        temp->next=temp->next->next;
    }
    else{
        temp=temp->next;
    }
}
return head;
    // code here
}

// Function to remove duplicates from Un-sorted linked list.
Node *removeDuplicates(Node *head) {
    // your code goes here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* nextNode=head->next;
    vector<int> elements;
    elements.push_back(curr->data);
    while(nextNode){
        auto it=find(elements.begin(),elements.end(),nextNode->data);
        if(it!=elements.end()){
            //element found
            
            //deleting node
            curr->next=nextNode->next;
            nextNode=curr->next;
        }
        else{
            //element not found
            curr=nextNode;
            elements.push_back(nextNode->data);
            nextNode=nextNode->next;
        }
    }
    return head;
}

Node* addOne(Node* head) {
    // Your Code here
    if(head==NULL){
        return head;
    }
    //reverse the linked list
    Node* prev=NULL;
    Node* curr=head;
    Node* next=curr->next;
    while(curr){
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next!=NULL)
        {
            next=next->next;
        }
    }
    //add 1
    head=prev;
    curr=head;
    int carry=1;
    int sum=0;
    while(curr->next!=NULL){
        sum=curr->data+carry;
        int digit=sum%10;
        carry=sum/10;
        curr->data=digit;
        curr=curr->next;
    // return head of list after adding one
    }
    sum=curr->data+carry;
    curr->data=sum%10;
    carry=sum/10;
    if(carry){
        //inserting new node;
        Node* newNode = new Node(carry);
        curr->next=newNode;
    }
    //final reversal;
    prev=NULL;
    curr=head;
    next=curr->next;
    while(curr){
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next!=NULL)
        {
            next=next->next;
        }
    }
    return prev;
}