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
    ListNode* merge(ListNode *node1,ListNode *node2)
    {
        if(node1==NULL) return node2;
        if(node2==NULL) return node1;
        ListNode *node=new ListNode();
        ListNode *ans=node;
        while(node1 && node2)
        {
            if(node1->val > node2->val) {
                node->next=node2;
                node2=node2->next;
            }
            else{
                node->next=node1;
                node1=node1->next;
            }
            node=node->next;
        }
        if(node1) node->next=node1;
        if(node2) node->next=node2;
        
        return ans->next;
    }
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        vector<ListNode *> newList;
        int i=0;
        if(lists.size() % 2 !=0){
            i++;
            newList.push_back(merge(lists[0],NULL));
        }
        for(;i<lists.size();i=i+2)
        {
            newList.push_back(merge(lists[i],lists[i+1]));
        }
         
        return mergeKLists(newList); 
    }

    /*
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
        solve(node,lists);
        return ans->next;
    }
    */
};