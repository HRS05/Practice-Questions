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
    
    bool isValidBST(TreeNode* root) {
       TreeNode *prev=NULL;
        return validate(root,prev);
    }
    
    bool validate(TreeNode *node,TreeNode *&prev)
    {
        if(node==NULL) return true;
        if(!validate(node->left,prev)) return false;
        if(prev!=NULL && prev->val >= node->val) return false;
        prev=node;
        return validate(node->right,prev);
    }
    
    
//     bool helper(TreeNode *root,TreeNode *prev)
//     {
//         if(root==NULL) return true;
//         if(!helper(root->left,prev)) return false;
//         if(prev && prev->val >= root->val) return false;
//         prev=root;
//         return helper(root->right,prev);
//     }   
    
//     bool isValidBST(TreeNode* root) {
//         TreeNode *prev=NULL;
//         return helper(root,prev);
//     }
};