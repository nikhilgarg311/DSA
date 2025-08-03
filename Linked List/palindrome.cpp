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
    ListNode* getMiddle(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverseHalf(ListNode* &head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;

        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }

        //step1->find middle
        ListNode* middle=getMiddle(head);

        //step2-> reverse after middle
        ListNode* temp= middle->next;
        middle->next=reverseHalf(temp);

        //step3-> compare
        ListNode* head1=head;
        ListNode* head2=middle->next;
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        // reverse back the half
        temp=middle->next;
        middle->next=reverseHalf(temp);

        return true;
    }
};