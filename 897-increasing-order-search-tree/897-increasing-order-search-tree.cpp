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
    TreeNode *node=new TreeNode(0);
    void f(TreeNode *root)
    {
        if(root==NULL) return;
        f(root->left);
        root->left=NULL;
        node->right=root;
        node=root;
        f(root->right);
    }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *ans;
        ans=node;
        f(root);
        return ans->right;
    }
};