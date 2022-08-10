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
    
    bool helper(TreeNode *root,long mmin,long mmax)
    {
        if(root==NULL) return true;
        if(root->val >=mmax || root->val <=mmin) return false;
        return helper(root->left,mmin,root->val) && helper(root->right,root->val,mmax);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
    
    /*
    bool helper(TreeNode *root,TreeNode *&prev)
    {
        if(root==NULL) return true;
        if(!helper(root->left,prev)) return false;
        if(prev && prev->val >= root->val) return false;
        prev=root;
        return helper(root->right,prev);
    }   
    
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=NULL;
        return helper(root,prev);
    }
    */
};