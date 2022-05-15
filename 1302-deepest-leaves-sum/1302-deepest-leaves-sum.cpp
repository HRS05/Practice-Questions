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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode *t;
        int size,i,sum;
        if(root==NULL) return 0;
        q.push(root);
        while(!q.empty())
        {
            size=q.size();
            sum=0;
            for(i=0;i<size;i++)
            {
                t=q.front(); q.pop();
                if(t->left==NULL && t->right==NULL) sum=sum+(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(q.size()==0) return sum; 
        }
        return sum;
    }
};