Node* findFirstNode(Node* head) {
        // your code here
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    
    // your code here
    Node* slow=head;
    Node* fast=head;
    
    slow=slow->next;
    fast=fast->next->next;
    
    while(fast && fast->next){
        if(slow==fast){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast){
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    return NULL;
    }