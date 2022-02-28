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
    
    ListNode* reverse(ListNode *root)
    {
        if(root==NULL || root->next==NULL) return root;
        ListNode *node=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        return node;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *startNode=NULL,*startPrev=NULL;
        ListNode *endNode=NULL,*endNext=NULL;
        ListNode *curr=head;
        int i;
        for(i=1;i<left;i++)
        {
            startPrev=curr;
            curr=curr->next;
        }
        startNode=curr;
        
        for(;i<right;i++)
        {
            curr=curr->next;
        }
        endNode=curr;
        endNext=curr->next;
        
        if(startPrev==NULL)
        {
            endNode->next=NULL;
            ListNode *x=startNode;
            head=reverse(startNode);
            x->next=endNext;
        }
        else
        {
            startPrev->next=NULL;
            endNode->next=NULL;
            ListNode *x=startNode;
            startPrev->next=reverse(startNode);
            x->next=endNext;
        }
            
        return head;
    }
};