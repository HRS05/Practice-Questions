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
    
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans{0};
        queue<pair<TreeNode *,unsigned long long> > q;
        q.push({root,0});
        while(!q.empty())
        {
            unsigned long long size=q.size();
            unsigned long long first_non_null_number_at_level=q.front().second;
            unsigned long long last_non_null_number_at_level=q.front().second;
            for(unsigned long long i=0;i<size;i++)
            {
                TreeNode *node=q.front().first;
                last_non_null_number_at_level=q.front().second;
                q.pop();
                if(node->left) q.push({node->left,2*last_non_null_number_at_level});
                if(node->right) q.push({node->right,2*last_non_null_number_at_level+1});
            } 
            ans=max(ans,(last_non_null_number_at_level-first_non_null_number_at_level));
        }
        return ans+1;
    }
    
    
    /*
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int count=0;
            int lastCount;
            int f=-1,l=-1;
            bool first=true;
            for(int i=0;i<size;i++)
            {
                TreeNode *node=q.front(); q.pop();
                if(node) {
                    q.push(node->left);
                    q.push(node->right);
                }else{
                    q.push(NULL);
                    q.push(NULL);
                }
                if(node && first)
                {
                    f=i;
                    first=false;
                }
                if(node)
                {
                    l=i;
                }
            }
            if(l==-1 && f==-1) break;
            ans=max(ans,(l-f));
        }   
        return ans+1;
    }*/
};