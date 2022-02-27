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
public:
    
    ListNode* sort(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode *dummy=new ListNode(-1);
        ListNode *ans=dummy;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                dummy->next=l1;
                l1=l1->next;
            }
            else
            {
                dummy->next=l2;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        if(l1) dummy->next=l1;
        if(l2) dummy->next=l2;
        
        return ans->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        
        head=sortList(head);
        fast=sortList(fast);
        return sort(head,fast);
    }
};