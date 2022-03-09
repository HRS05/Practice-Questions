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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *ans=new ListNode(0);
        ListNode *newHead=ans;
        ListNode *nex=head->next;
        while(head!=NULL)
        {
            if(nex && head->val == nex->val)
            {
            ans->next=NULL;
            while(head!=NULL && head->val==nex->val) head=head->next;
            if(head)nex=head->next;
            }
            else
            {
                ans->next=head;
                head=head->next;
                ans=ans->next;
                if(nex)nex=nex->next;
            }
        }
        return  newHead->next;
    }
};