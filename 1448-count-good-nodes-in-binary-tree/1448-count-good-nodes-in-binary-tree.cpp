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
    
    int helper(TreeNode *root,int lastValue)
    {
        if(root==NULL) return 0;
        int ans=0;
        if(root->val >= lastValue) {
            ans++;
            lastValue=root->val;
        }
        return ans+helper(root->left,lastValue)+helper(root->right,lastValue);
    }
    
    int goodNodes(TreeNode* root) {
        return helper(root,INT_MIN);
    }
};