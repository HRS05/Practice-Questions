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
    
    TreeNode * findRightMost(TreeNode *node)
    {
        if(node->right==NULL) return node;
        return findRightMost(node->right);
    }
    
    TreeNode * helper(TreeNode *node)
    {
        if(node->left==NULL) return node->right;
        if(node->right==NULL) return node->left;
        
        TreeNode *n1=node->right;
        TreeNode *n2=findRightMost(node->left);
        n2->right=n1;
        //n2->left=node->left;
        return node->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val == key) return helper(root);
        
        TreeNode *node=root;
        while(node)
        {
            if(node->val > key)
            {
                if(node->left && node->left->val == key)
                {
                    node->left=helper(node->left);
                    break;
                }
                else node=node->left;
            }
            else
            {
                if(node->right && node->right->val == key)
                {
                    node->right=helper(node->right);
                    break;
                }
                else node=node->right;
            }
        }
        
        return root;
        
    }
};