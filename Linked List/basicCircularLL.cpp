#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insertAfterElement(Node* &tail, int element, int data){

    //empty list
    if(tail==NULL){
        Node* newNode= new Node(data);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        Node* curr= tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* newNode= new Node(data);
        newNode->next=curr->next;
        curr->next=newNode;
    }
}

void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=tail);
    cout<<endl;
}

void deleteByValue(Node* &tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"Empty List";
        return;
    }

    Node* prev=tail;
    Node* curr=prev->next;
    while(curr->data!=value){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    //1 node case
    if(curr==prev){
        tail=NULL;
    }
    //more than 1 node
    if(curr==tail){
        tail=prev;
    }
    curr->next=NULL;
    delete curr;
}

int main(){
    Node* tail=NULL;

    insertAfterElement(tail,5,3);
    print(tail);
    insertAfterElement(tail,3,5);
    print(tail);
    insertAfterElement(tail,5,7);
    print(tail);
    insertAfterElement(tail,7,9);
    print(tail);
    insertAfterElement(tail,5,6);
    print(tail);
    insertAfterElement(tail,3,4);
    print(tail);
    deleteByValue(tail,3);
    print(tail);
    deleteByValue(tail,6);
    print(tail);
}