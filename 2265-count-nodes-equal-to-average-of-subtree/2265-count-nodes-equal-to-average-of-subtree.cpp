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

    pair<int,int> solve(TreeNode *root,int &ans)
    {
        if(root == NULL) return {0,0};
        pair<int,int> l,r,res;
        l.first=l.second=r.first=r.second=0;
        if(root->left) l = solve(root->left,ans);
        if(root->right) r = solve(root->right,ans);
        res.first = l.first + r.first + 1;
        res.second = l.second + r.second + root->val;
        if((res.second/res.first) == root->val) ans++;
        return res;
    }


    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};