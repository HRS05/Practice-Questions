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
    int diameterOfBinaryTree(TreeNode* root) {
        int height=0;
        return calculate(root,&height)-1;
    }
    int calculate(TreeNode *root,int *height)
    {
        if(root==NULL)
        {
            *height=0;
            return 0;
        }
        int lh=0,rh=0;
        int lDiameter=calculate(root->left,&lh);
        int rDiameter=calculate(root->right,&rh);
        int currDiameter=lh+rh+1;
        *height=max(lh,rh)+1;
        return max(currDiameter,max(lDiameter,rDiameter));
            
    }
};