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
    void findPaths(TreeNode *root,vector<vector<int> > &ans,vector<int> &res,int targetSum)
    {
        if(root==NULL)return ;
        
        res.push_back(root->val);
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
        {
            ans.push_back(res);
        }
        
        findPaths(root->left,ans,res,targetSum-root->val);
        findPaths(root->right,ans,res,targetSum-root->val);
       res.pop_back();
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > ans;
        vector<int> res;
        findPaths(root,ans,res,targetSum);
        return ans;
    }
};