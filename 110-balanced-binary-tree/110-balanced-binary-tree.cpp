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
    
    bool check(TreeNode *root,int &height)
    {
        if(root==NULL)
        {
            height=0;
            return true;
        }
        int lh=0,rh=0;
        bool lCheck=false,rCheck=false;
        lCheck=check(root->left,lh);
        rCheck=check(root->right,rh);
        height=max(lh,rh)+1;
        
        if(abs(lh-rh)>1) return false;
        else return lCheck && rCheck;
        
    }
    
    bool isBalanced(TreeNode* root) {
        int height=0;
        return check(root,height);
    }
};