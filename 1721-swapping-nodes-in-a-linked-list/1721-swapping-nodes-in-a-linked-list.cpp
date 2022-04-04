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
    ListNode* swapNodes(ListNode* head, int k) {
        int size=numberOfNodes(head);
        ListNode *x,*y,*t,*xx,*yy,*z;
        t=head;
        int count=1;
        while(t!=NULL)
        {
            if(count==k) x=t;
            if(count==(size-k)) { y=t; }
            t=t->next;
            count++;
        }
        int v;
        v=x->val;
        x->val=y->val;
        y->val=v;
        return head;
    }
    
    int numberOfNodes(ListNode *head)
    {
        ListNode *t;
        t=head;
        int count=1;
        while(t!=NULL) 
        {    
            t=t->next;
            count++;
        }   
        return count;
    }
};