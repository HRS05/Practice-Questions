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
    
    void getValue(TreeNode *root,TreeNode *&prev,int &ans)
    {
        if(root==NULL) return ;
        getValue(root->left,prev,ans);
        if(prev)
        {
            ans=min(ans,root->val - prev->val);
            cout<<"root->val  "<<root->val<<endl;
            cout<<"prev->val  "<<prev->val<<endl;
            cout<<"ans  "<<ans<<endl;
        }
        prev=root;
        getValue(root->right,prev,ans);
    }
    
    int minDiffInBST(TreeNode* root) {
        TreeNode *prev=NULL;
        int ans=INT_MAX;
        getValue(root,prev,ans);
        return ans;
    }
};