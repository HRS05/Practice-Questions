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
    int maxLevelSum(TreeNode* root) {
        TreeNode *t;
        int maxSum=INT_MIN;
        int maxLevel=0;
        int level=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int currMaxSum=0;
            for(int i=0;i<size;i++)
            {
                t=q.front(); q.pop();
                currMaxSum=currMaxSum+t->val;
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            if(maxSum < currMaxSum) {
                maxSum=currMaxSum;;
                maxLevel=level;
            }
            level++;
        }
        return maxLevel;
    }
};