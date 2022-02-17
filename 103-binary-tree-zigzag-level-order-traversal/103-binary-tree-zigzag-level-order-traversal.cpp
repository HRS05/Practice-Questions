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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        deque<TreeNode *> q;
        TreeNode *node;
        q.push_back(root);
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> v;
            for(int i=0;i<size;i++)
            {
               
                 node=q.front(); q.pop_front();
                    v.push_back(node->val);
                   if(node->left!=NULL) q.push_back(node->left);
                   if(node->right!=NULL) q.push_back(node->right);
                    
               
            }
            if(level%2==0) reverse(v.begin(),v.end());
            level++;
            ans.push_back(v);
        }
        return ans;
    }
};