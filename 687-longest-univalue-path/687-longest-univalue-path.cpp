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
    int ans{0};
    int helper(TreeNode *root,int val){
        if(root==NULL) return 0;
        int lh=helper(root->left,root->val);
        int rh=helper(root->right,root->val);
        ans=max(ans,(lh+rh));
        return val==root->val ? 1+max(lh,rh) : 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        helper(root,-10001);
        return ans;
    }
    
    /*
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int lCal=helper(root->left,root->val);
        int rCal=helper(root->right,root->val);
        int lValue=longestUnivaluePath(root->left);
        int rValue=longestUnivaluePath(root->right);
        return max({(lCal+rCal),lValue,rValue});
    }
    
    int helper(TreeNode *root,int val)
    {
        if(root==NULL) return 0;
        if(root->val != val) return 0;
        return 1+max(helper(root->left,root->val),helper(root->right,root->val));
    }
    */
};