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

bool isCircular(Node *head) {
        // Your code here
        if(head==NULL){
            return true;
        }
        if(head->next==head){
            return true;
        }
        Node* temp=head->next;
        while(temp!=NULL&& temp->next!=head){
            temp=temp->next;
        }
        if(temp==NULL || temp->next==NULL){
            return false;
        }
        return true;
    }