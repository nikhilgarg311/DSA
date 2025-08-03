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