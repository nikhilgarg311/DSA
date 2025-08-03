Node *moveToFront(Node *head) {
    // code here
    if(head==NULL|| head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* nextNode=head->next;
    while(nextNode->next!=NULL){
        curr=nextNode;
        nextNode=nextNode->next;
    }
    curr->next=NULL;
    nextNode->next=head;
    head=nextNode;
    return head;
}