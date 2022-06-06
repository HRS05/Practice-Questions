/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA=0;
        int countB=0;
        ListNode *aNode,*bNode;
        aNode=headA;
        while(aNode!=NULL) {
            countA++;
            aNode=aNode->next;
        }
        bNode=headB;
        while(bNode!=NULL) {
            countB++;
            bNode=bNode->next;
        }
        aNode=headA;
        bNode=headB;
        if(countA>countB){
            while(countA!=countB){
                countA--;
                aNode=aNode->next;
            }
        }
        else
        {
            while(countA!=countB){
                countB--;
                bNode=bNode->next;
            }
        }
        while(aNode!=bNode){
            aNode=aNode->next;
            bNode=bNode->next;
        }
        return aNode;
    }
};