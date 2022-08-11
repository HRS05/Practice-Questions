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
    void helper(TreeNode *root,string s,string &ans)
    {
        if(root==NULL) return ;
         if(root->left==NULL && root->right==NULL){
             s=char(root->val+97)+s;
             
             if(ans=="") ans=s;
             else if(ans > s) ans=s;
             
            return;
        }
             s=char(root->val+97)+s;
        helper(root->left,s,ans);
       
        helper(root->right,s,ans);
        
        
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        string s;
        string ans="";
        helper(root,s,ans);
        return ans;
    } 
};