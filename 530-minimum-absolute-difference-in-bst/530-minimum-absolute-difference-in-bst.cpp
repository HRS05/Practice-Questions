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
    void getValues(TreeNode *root,TreeNode *&prev,int &ans)
    {
        if(root==NULL) return ;
        getValues(root->left,prev,ans);
        if(prev)
        {
            ans=min(ans,abs(root->val - prev->val));
        }
        prev=root;
        getValues(root->right,prev,ans);
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev=NULL;
        int ans=INT_MAX;
        getValues(root,prev,ans);
        return ans;
    }
};