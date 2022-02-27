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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty())
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                TreeNode *node=st.top()->right;
                if(node==NULL)
                {
                    TreeNode *t=st.top(); st.pop();
                    ans.push_back(t->val);
                    while(!st.empty() && t==st.top()->right)
                    {
                        t=st.top(); st.pop();
                        ans.push_back(t->val);
                    }
                }
                else
                {
                    root=node;
                }
            }
        }
        return ans;
    }
};