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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        while(head && head->val==val)
        {
            head=head->next;
        }
        ListNode *node=head;
        ListNode *prev=NULL;
        while(node!=NULL)
        {
            if(node->val==val)
            {
                prev->next=node->next;
                node=node->next;
            }
            else
            {
                prev=node;
                node=node->next;
            }
        }
        return head;
    }
};