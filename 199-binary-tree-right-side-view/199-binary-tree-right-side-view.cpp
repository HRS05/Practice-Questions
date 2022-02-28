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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode *t;
        queue<TreeNode*> q;
        int size,i;
        vector<int> v;
        if(root==NULL) return v;
        q.push(root);
        while(!q.empty())
        {
            size=q.size();
            for(i=0;i<size;i++)
            {
                t=q.front(); q.pop();
                if(i==0) v.push_back(t->val);
                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);    
            }
        }
        return v;
    }
    
    //using DFS
    /*
    void preorder(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL) return ;
        if (res.size() < level) res.push_back(root->val);
        preorder(root->right, level + 1, res);
        preorder(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        preorder(root, 1, res);
        return res;
    }
    */
    
    
};