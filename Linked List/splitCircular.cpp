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

pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        if(head==NULL){
            
        }
        Node* list1=head;
        Node* list2=NULL;
        Node* temp=head->next;
        Node*temp2=NULL;
        int count=1;
        while(temp!=head){
            temp=temp->next;
            count=count+1;
        }
        //odd nodes
        if(count%2==1){
            for(int i=1;i<=count/2;i++){
                temp=temp->next;
            }
            list2=temp->next;
            temp2=temp->next;
            temp->next=head;
            for(int i=1;i<count/2;i++){
                temp2=temp2->next;
            }
            temp2->next=list2;
            
        }else{
            //even nodes
            for(int i=1;i<count/2 ;i++){
                temp=temp->next;
            }
            list2=temp->next;
            temp2=temp->next;
            temp->next=head;
            for(int i=1;i<count/2;i++){
                temp2=temp2->next;
            }
            temp2->next=list2;
        }
        return {list1,list2}; 
    }