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
    void getPaths(TreeNode *root,string s,vector<string> &vs)
    {
        if(root==NULL) return;
        
        
           s=s+"->"+to_string(root->val);
           getPaths(root->left,s,vs);
           getPaths(root->right,s,vs);
           //s.pop_back();
       if(root->left==NULL && root->right==NULL) 
        {
            vs.push_back(s);
        }
                
                
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vs;
        string s=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
             vs.push_back(s);
            return vs;
        }
        getPaths(root->left,s,vs);
        getPaths(root->right,s,vs);
        return vs;
    }
};