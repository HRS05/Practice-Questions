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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL)
        {
            TreeNode *root=new TreeNode(head->val);
            return root;
        }
        ListNode *prev=middleNode(head);
        ListNode *middle=prev->next;
        TreeNode *root=new TreeNode(middle->val);
        
        prev->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(middle->next);
        return root;
        
    }
};