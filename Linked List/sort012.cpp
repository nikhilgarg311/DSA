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


//--------APPROACH ONE-------//
void sort012(Node* &head){ //data replacement
    Node* temp=head;
    int count[3]={0}; 
    while(temp!=NULL){ 
        count[temp->data]++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(count[0]!=0){
            temp->data=0;
            count[0]--;
        }
        else if(count[1]!=0){
            temp->data=1;
            count[1]--;
        }
        else if(count[2]!=0){
            temp->data=2;
            count[2]--;
        }
        temp=temp->next;
    }
    return;
}



//--------APPROACH TWO---------//
void insertNodeAtTail(Node* &tail,Node* curr){
    tail->next=curr;
    tail=curr;
}
void sortPartTwo(Node* &head){ //data replacement not allowed
   Node* zeroHead=new Node(-1);
   Node* zeroTail=zeroHead;
   Node* oneHead=new Node(-1);
   Node* oneTail=oneHead;
   Node* twoHead=new Node(-1);
   Node* twoTail=twoHead;

    Node* curr=head;
    //creating separate list for 0,1,2
    while(curr!=NULL){
        if(curr->data==0){
            insertNodeAtTail(zeroTail,curr);
        }
        else if(curr->data==1){
            insertNodeAtTail(oneTail,curr);
        }
        else if(curr->data==2){
            insertNodeAtTail(twoTail,curr);
        }
        curr=curr->next;
    }
    //merging lists
    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }
    oneTail->next=twoHead->next;
    twoTail->next=NULL;

    //setup head
    head=zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;
}




//print the linked list
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
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

    Node* node1= new Node(1);
    Node* head =node1;

    print(head);
    //inserting at head
    insert(head,2,0);
    insert(head,3,1);
    insert(head,4,0);
    insert(head,5,2);
    insert(head,6,1);
    insert(head,7,2);
    print(head);
    // sort012(head);
    // print(head);
    sortPartTwo(head);
    print(head);
}