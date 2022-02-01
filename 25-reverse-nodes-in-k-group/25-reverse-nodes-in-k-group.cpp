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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr,*prev,*next;
        int i=0;
        //checking
        curr=head;
        while(i<k && curr!=NULL)
        {
            i++;
            curr=curr->next;
        }
        if(i!=k) return head;
        
        prev=NULL;
        next=NULL;
        curr=head;
        i=0;
        while(i<k && curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        if(next!=NULL) head->next=reverseKGroup(next,k);
        return prev;
    }
};