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
    ListNode* swapPairs(ListNode* node) {
    ListNode *p;
    ListNode *n;
    ListNode *pp=NULL;
    ListNode *newHead;
    if(node==NULL) return NULL;
    p=node;
    n=node->next;
    newHead=n;
    if(n==NULL) return node;
    while(p!=NULL && p->next!=NULL)
    {
        p->next=n->next;
        n->next=p;
        if(pp!=NULL)
        {
            pp->next=n;
        }

        pp=p;
        p=p->next;
        if(p)n=p->next;
    }
    
    return newHead;
    }
};