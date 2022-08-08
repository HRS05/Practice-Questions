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
    
    int helper(TreeNode *root,int &val)
    {
        if(root==NULL)
        {
            //val=0;
            return -1e9;
        }
        int lget=max(0,helper(root->left,val));
        int rget=max(0,helper(root->right,val));
        val=max(val,root->val+lget+rget);
        return max(lget,rget)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int val=-1e9;
        helper(root,val);
        return val;
    }
};