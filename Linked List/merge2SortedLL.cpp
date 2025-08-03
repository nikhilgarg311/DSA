/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
void solve(ListNode* &list1,ListNode* &list2){
    ListNode* prev = list1;
    ListNode* curr = list1->next;
    ListNode* temp= list2;
    while(temp!=NULL && curr!=NULL){
        if((temp->val<curr->val) && (temp->val>=prev->val)){
        //put node in between
        list2=temp->next;
        temp->next=curr;
        prev->next=temp;
        prev=temp;
        temp=list2;
    }
    else{
        //slide ahead
        prev=curr;
        curr=curr->next;
    }
    }
    if(list2==NULL){
        //list is now merged
    }
    if(curr==NULL && list2!=NULL){
        prev->next=list2;
    }
    
}

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        //if first element of list1 is smaller
        if(list1->val<=list2->val){
            solve(list1,list2);
            return list1;
        }
        else{
            solve(list2,list1);
            return list2;
        }
    }
};