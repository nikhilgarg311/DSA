#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data=data;
            this->next=NULL;
            this->next=NULL;
        }
};

//forward traverse the linked list
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

//backward traverse the linked list
void printReverse(Node* head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }cout<<endl;
}

void insertAtHead(Node* &head,int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        return;
    }
    Node* temp =new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertAtPosition(Node* &head,int data,int position){
    if(position==1){
        insertAtHead(head,data);
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        count++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        //we are inserting at tail
        Node * nodeToInsert=new Node(data);
        nodeToInsert->prev=temp;
        temp->next=nodeToInsert;
    }
    else{
        Node* nodeToInsert=new Node(data);
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        temp->next=nodeToInsert;
        nodeToInsert->prev=temp;
    }

}

void deleteByPosition(Node* &head,int position){
    Node* curr=head;
    if(position==1){
        //we are deleting at head
        head=head->next;
        head->prev=NULL;
        delete curr;
        return;
    }
    int count=1;

    while(count<position){
        count++;
        curr=curr->next;
    }

    if(curr->next!=NULL){
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
        delete curr;
    }
    else if(curr->next==NULL){
        curr->prev->next=NULL;
        delete curr;
    }
}

int main(){
    Node* node1=new Node(15);
    Node* head=node1;

    insertAtHead(head,10);
    print(head);

    insertAtPosition(head,25,3);
    print(head);

    insertAtPosition(head,5,3);
    print(head);

    printReverse(head);

    deleteByPosition(head,4);
    print(head);
}