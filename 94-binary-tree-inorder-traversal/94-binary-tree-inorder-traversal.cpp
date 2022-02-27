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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *t,*k;
        vector<int> v;
        for(t=root;t!=NULL;t=t->left) s.push(t);
        while(!s.empty())
        {
            t=s.top();  s.pop();
            v.push_back(t->val);
            for(k=t->right;k!=NULL;k=k->left) s.push(k);
        }
        return v;
    }
};