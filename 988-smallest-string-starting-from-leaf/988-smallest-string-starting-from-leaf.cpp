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
    void helper(TreeNode *root,string s,vector<string> &strings)
    {
        if(root==NULL) return ;
         if(root->left==NULL && root->right==NULL){
             s=char(root->val+97)+s;
             
             strings.push_back(s);
             
            return;
        }
             s=char(root->val+97)+s;
        helper(root->left,s,strings);
       
        helper(root->right,s,strings);
        
        
    }
    
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> strings;
        string s;
        helper(root,s,strings);
        sort(strings.begin(),strings.end());
        return strings[0];
    } 
};