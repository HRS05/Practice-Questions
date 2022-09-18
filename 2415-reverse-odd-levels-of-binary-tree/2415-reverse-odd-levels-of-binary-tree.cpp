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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL || root->left==NULL) return root;
        queue<TreeNode *> q;
        q.push(root);
        int level=0;
        vector<int> v;
        while(!q.empty())
        {
            int size=q.size();
            if(level%2==0) v.clear();
            //else reverse(v.begin(),v.end());
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front(); q.pop();
                if(level % 2 == 0){
                    if(node->left){
                        v.push_back(node->left->val);
                        v.push_back(node->right->val);
                    }
                }else
                {
                    node->val=v[size-1-i];
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return root;
    }
};