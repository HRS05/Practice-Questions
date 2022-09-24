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
    void solve(ListNode *node,vector<ListNode*> &lists)
    {
        while(1)
        {
        int minVal=INT_MAX;
            bool flag=true;
       for(ListNode * root : lists)
        {
            if(root && root->val < minVal) minVal=root->val;
            if(root!=NULL) flag=false;
        }
            if(flag) break;
       for(int i=0;i<lists.size();i++)
           {

           if(lists[i] && lists[i]->val == minVal)
           {
               node->next = lists[i];
               lists[i]=lists[i]->next;
               node=node->next;
               break;
           }
       } 
        }
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *node,*ans;
        node=new ListNode();
        ans=node;
        //vector<ListNode *> pointers(lists.size());
        
        solve(node,lists);
        
        
        return ans->next;
    }
};