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

//print the linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// reverse in groups
Node* reverseInGroups(int k,Node* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    int i=1;
    while(i<=k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        i++;
    }
    head->next=reverseInGroups(k,curr);
    return prev;
}

//insert at head
void insertAtHead(Node* &head, int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

//insert at tail
void insertAtTail(Node* &head,int data){
    Node* nodeToInsert=new Node(data);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nodeToInsert;
}

//insert at any position including head and tail
void insert(Node* &head,int position,int data){

    if(position==1){
        //this means insert at head
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int count=1; //we will already be at position 1
    while(count<position-1 && temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    if(temp->next==NULL){
        insertAtTail(head,data);
        return;
    }
    Node* nodeToinsert=new Node(data);
    nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
}

int main(){

    Node* node1= new Node(10);
    Node* head =node1;

    print(head);
    //inserting at head
    insert(head,1,5);
    print(head);

    //inserting at tail
    insert(head,3,20);
    print(head);

    //inserting in mid
    insert(head,3,15);
    print(head);

    //inserting at some place ahead of tail, our function will handle automatically
    insert(head,15,3);
    print(head);

    insert(head,3,13);
    print(head);

    head=reverseInGroups(2,head);
    print(head);

}