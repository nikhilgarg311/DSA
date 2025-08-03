Node* reverseList(struct Node* head) {
        // code here
        Node* prev=NULL;
        Node* curr=head;
        Node* next=curr->next;
        while(next!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //curr->next=prev;
        return prev;
        
}

Node *reverseKGroup(Node *head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        Node* forward=NULL;
        // code here
        int count=1;
        while(count<=k && curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        
        head->next=reverseKGroup(curr,k);
        return prev;
        
}

bool detectLoop(Node* head) {
    if(head->next==head){
        return true;
    }
    if(head->next==NULL){
        return false;
    }
    
    // your code here
    Node* slow=head;
    Node* fast=slow->next;
    
    while(slow->next!=NULL){
        if(slow==fast){
            return true;
        }
        slow=slow->next;
        if(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            
        }
        else{
            return false;
        }
    }
    return false;
}

void removeLoop(Node* head) {
  
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;
    slow=slow->next;
    fast=fast->next->next;
    // Move slow and fast 1 and 2 steps ahead respectively.
    while(fast && fast->next){
        if(slow==fast){
            break;
        }
        
        slow=slow->next;
        fast=fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}

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

//remove duplicates from sorted LL
Node* removeDuplicates(Node* head) {

    // code here
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* nextNode=head->next;
    while(nextNode!=NULL){
        if(curr->data==nextNode->data){
            curr->next=nextNode->next;
            if(curr && curr->next){
                nextNode=curr->next;
            }
            else{
                break;
            }
            
        }
        else{
            curr=curr->next;
            nextNode=nextNode->next;
        }
    }
    return head;
}

//remove duplicates from a unsorted LL
Node *removeDuplicates(Node *head) {
    // your code goes here
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* nextNode=head->next;
    vector<int> elements;
    elements.push_back(curr->data);
    while(nextNode){
        auto it=find(elements.begin(),elements.end(),nextNode->data);
        if(it!=elements.end()){
            //element found
            
            //deleting node
            curr->next=nextNode->next;
            nextNode=curr->next;
        }
        else{
            //element not found
            curr=nextNode;
            elements.push_back(nextNode->data);
            nextNode=nextNode->next;
        }
    }
    return head;
}

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

/////////////////////-----------------------------------------------////////////////////////////////
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=curr->next;
    while(curr){
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next){
            next=next->next;
        }
    }
    return prev;
}

Node* removeLeadingZeros(Node* head){

    Node* curr=head;
    Node* temp=NULL;
    while(curr && curr->data==0){
        temp=curr->next;
        curr->next=NULL;
        curr=temp;
    }
    return curr;
}

    
Node* addTwoLists(Node* num1, Node* num2) {
    // code here
    //remove leading zeros
    num1=removeLeadingZeros(num1);
    num2=removeLeadingZeros(num2);
    Node* reversedNum1=reverse(num1);
    Node* reversedNum2=reverse(num2);
    int sum=0,carry=0;
    Node* curr1=reversedNum1;
    Node* curr2=reversedNum2;
    while(curr1->next!=NULL && curr2->next!=NULL){
        
        sum=curr1->data+curr2->data+carry;
        curr1->data=sum%10;
        carry=sum/10;
        
        curr1=curr1->next;
        curr2=curr2->next;
        
    }
    if(curr1->next==NULL && curr2->next!=NULL){
        sum=curr2->data+curr1->data+carry;
        curr1->data=sum%10;
        carry=sum/10;
        
        curr2=curr2->next;
        while(curr2){
            sum=curr2->data+carry;
            Node* newNode= new Node(sum%10);
            curr1->next=newNode;
            curr1=curr1->next;
            carry=sum/10;
            curr2=curr2->next;
        }
        if(carry){
            Node* newNode= new Node(carry);
            curr1->next=newNode;
        }
    }
    else if(curr2->next==NULL && curr1->next!=NULL){
        sum=curr2->data+curr1->data+carry;
        curr1->data=sum%10;
        carry=sum/10;
        
        curr2=curr2->next;
        curr1=curr1->next;
        while(curr1->next!=NULL){
            sum=curr1->data+carry;
            curr1->data=sum%10;
            carry=sum/10;
            curr1=curr1->next;
        }
        sum=curr1->data+carry;
        curr1->data=sum%10;
        carry=sum/10;
        if(carry){
            Node* newNode= new Node(carry);
            curr1->next=newNode;
        }else{
            curr1=curr1->next;
        }
    }
    else{
        sum=curr2->data+curr1->data+carry;
        curr1->data=sum%10;
        carry=sum/10;
        if(carry){
            Node* newNode= new Node(carry);
            curr1->next=newNode;
        }
        else{
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
    }
    num1=reverse(reversedNum1);
    return num1;
}
/////////////////////-----------------------------------------------////////////////////////////////
bool isCircular(Node *head) {
    // Your code here
    if(head==NULL){
        return true;
    }
    if(head->next==NULL){
        return false;
        
    }
    Node* curr=head->next;
    while(curr){
        if(head==curr){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

pair<Node *, Node *> splitList(struct Node *head) {
    // code here
    if(head==NULL){
    }
    
    //step1: counting nodes
    struct Node* curr=head->next;
    int count=1;
    while(curr){
        if(head==curr->next){
            count++;
            break;
        }
        curr=curr->next;
        count++;
    }
    struct Node* curr2=curr;
    struct Node* head2=NULL;
    int temp=1;
    curr=head;
    //even
    if(count%2==0){
        while(temp<count/2){
            curr=curr->next;
            temp++;
        }
        head2=curr->next;
        curr->next=head;
        curr2->next=head2;
    }
    else{
        while(temp<=count/2){
            curr=curr->next;
            temp++;
        }
        head2=curr->next;
        curr->next=head;
        curr2->next=head2;
    }
    return {head,head2};
}

//sort 0,1,2
Node* segregate(Node* head) {
    // code here
    int arr[3]={0};
    
    Node* curr=head;
    
    while(curr){
        if(curr->data==0){
            arr[0]++;
        }
        else if(curr->data==1){
            arr[1]++;
        }
        else{
            arr[2]++;
        }
        curr=curr->next;
    }
    Node* newHead= new Node(0);
    Node* ptr=newHead;
    for(int i=0; i<3;i++){
        
        for(int j=0;j<arr[i];j++){
            Node* newNode= new Node(i);
            ptr->next=newNode;
            ptr=ptr->next;
        }
    }
    return newHead->next;
    
}
//////////////---------------------------------//////////////////////////
Node* mergeTwoSortedLL(Node* list1,Node* list2){
    //use bottom instead of next in this
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    Node* curr1=list1;
    Node* curr2=list2;
    Node* head= new Node(0);
    Node* temp=head;
    while(curr1 && curr2){
        if(curr1->data<=curr2->data)
        {
            temp->bottom= curr1;
            curr1=curr1->bottom;
        }
        else{
            temp->bottom=curr2;
            curr2=curr2->bottom;
            
        }
        temp=temp->bottom;
    }
        while(curr1){
            temp->bottom= curr1;
            curr1=curr1->bottom;
            temp=temp->bottom;
        }
        while(curr2){
            temp->bottom= curr2;
            curr2=curr2->bottom;
            temp=temp->bottom;
        }
    return head->bottom;
}
// Function which returns the  root of the flattened linked list.
Node *flatten(Node *root) {
    // Your code here
    if(root==NULL || root->next==NULL){
        return root;
    }
    Node* down=root;
    //Step1: using recursion get right side sorted
    Node* right= flatten(root->next);
    
    down->next=NULL;
    //Step2: merge two sorted LL
    Node* result= mergeTwoSortedLL(down,right);
    return result;
}


///////////////////-------------------//////////////////////

Node* mergeTwoSortedLL(Node* list1,Node* list2){
    //use bottom instead of next in this
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    Node* curr1=list1;
    Node* curr2=list2;
    Node* head= new Node(0);
    Node* temp=head;
    while(curr1 && curr2){
        if(curr1->data<=curr2->data)
        {
            temp->next= curr1;
            curr1=curr1->next;
        }
        else{
            temp->next=curr2;
            curr2=curr2->next;
            
        }
        temp=temp->next;
    }
        while(curr1){
            temp->next= curr1;
            curr1=curr1->next;
            temp=temp->next;
        }
        while(curr2){
            temp->next= curr2;
            curr2=curr2->next;
            temp=temp->next;
        }
    return head->next;
}

    Node* helper(vector<Node*>& arr,int size){
        if(size<1){
            return NULL;
        }
        if(size==1){
            return arr[0];
        }
        Node* res=mergeTwoSortedLL(arr[size-1],arr[size-2]);
        arr[size-2]=res;
        size=size-1;
        return helper(arr,size);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int size= arr.size();
        return helper(arr,size);
        
    }

//////////////--------------------////////////////
    //function to break LL in two halves
    Node* getMiddle(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    //function to merge two LL in sorted way
    Node* mergeTwoSortedLL(Node* list1,Node* list2){
    //use bottom instead of next in this
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    Node* curr1=list1;
    Node* curr2=list2;
    Node* head= new Node(0);
    Node* temp=head;
    while(curr1 && curr2){
        if(curr1->data<=curr2->data)
        {
            temp->next= curr1;
            curr1=curr1->next;
        }
        else{
            temp->next=curr2;
            curr2=curr2->next;
            
        }
        temp=temp->next;
    }
        while(curr1){
            temp->next= curr1;
            curr1=curr1->next;
            temp=temp->next;
        }
        while(curr2){
            temp->next= curr2;
            curr2=curr2->next;
            temp=temp->next;
        }
    return head->next;
}
    
// Function to sort the given linked list using Merge Sort.
Node* mergeSort(Node* head) {
    // your code here
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* middle=getMiddle(head);
    Node* left=head;
    Node* right=middle->next;
    middle->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    
    return mergeTwoSortedLL(left,right);
}

//////////////////////-------------------//////////////////////////