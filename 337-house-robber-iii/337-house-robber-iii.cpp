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
    map<TreeNode *,int> mp;
    int rob(TreeNode* root) {
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp.find(root)->second;
        int sum=0;
        sum=sum+root->val;
        if(root->left!=NULL)
        {
            sum+=rob(root->left->left);
            sum+=rob(root->left->right);
        }
        if(root->right!=NULL)
        {
            sum+=rob(root->right->left);
            sum+=rob(root->right->right);
        }
        return mp[root]=max(sum,(rob(root->left)+rob(root->right)));
    }
};