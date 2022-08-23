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
     ListNode * reverse(ListNode *root)
    {
        if(root==NULL || root->next==NULL) return root;
        ListNode *node=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
         return node;
    }
    
    
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *node=reverse(slow);
        slow=head;
        while(node!=NULL){
            if(node->val != slow->val) return false;
            slow=slow->next;
            node=node->next;
        }
        return true;
    }
};