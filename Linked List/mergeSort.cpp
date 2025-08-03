/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            //firstNode
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        //step1: create a cloneList
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        //step2: change links
        Node* originalNode = head;
        Node* originalNext = NULL;
        Node* cloneNode = cloneHead;
        Node* cloneNext=NULL;
        
        while(originalNode!=NULL && cloneNode!=NULL){
            
            originalNext = originalNode->next;
            originalNode->next=cloneNode;
            originalNode=originalNext;

            cloneNext=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=cloneNext;
        }
        //step3: add randoms
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                if(temp->random!=NULL){
                    temp->next->random=temp->random->next;
                }
                else{
                    temp->next->random=NULL;
                }
            }
            if(temp->next!=NULL){
                temp=temp->next->next;
            }
        }

        //revert links change
        originalNode = head;
        originalNext = NULL;
        cloneNode = cloneHead;
        cloneNext=NULL;

        while(originalNode!=NULL && cloneNode!=NULL){
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL){
                cloneNode->next=originalNode->next;
            }
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};