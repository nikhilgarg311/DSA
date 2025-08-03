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
    ListNode* reverse(ListNode* &head){
        if(head==NULL|| head->next==NULL){
            return head;
        }
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
    ListNode* insertAtTail(ListNode* &head,int val){
        if(head==NULL){
            //firstNode
            ListNode* node1= new ListNode(val);
            head=node1;
            return head;
        }
        ListNode* newNode=new ListNode(val);
        head->next=newNode;
        return newNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse the LLs if not already reversed given
        // l1 = reverse(l1);
        // l2 = reverse(l2);

        //sum and carry
        ListNode* head=new ListNode(-1);
        ListNode* ptr=head;
        int carry=0;
        int sum=0,digit=0;
        while(l1!=NULL && l2!=NULL){
            sum=l1->val+l2->val+carry;
            digit=sum%10;
            carry=sum/10;
            ptr=insertAtTail(ptr,digit);
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL && l2==NULL && carry!=0){
            ptr=insertAtTail(ptr,carry);
        }
        if(l1==NULL && l2!=NULL){
            while(l2!=NULL){
                sum=l2->val+carry;
                digit=sum%10;
                carry=sum/10;
                ptr=insertAtTail(ptr,digit);
                l2=l2->next;
            }
            if(carry!=0){
                ptr=insertAtTail(ptr,carry);
            }
        }
        if(l2==NULL && l1!=NULL){
            while(l1!=NULL){
                sum=l1->val+carry;
                digit=sum%10;
                carry=sum/10;
                ptr=insertAtTail(ptr,digit);
                l1=l1->next;
            }
            if(carry!=0){
                ptr=insertAtTail(ptr,carry);
            }
        }
        return head->next;
    }
};