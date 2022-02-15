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
    
    TreeNode * construct(vector<int> &postorder,map<int,int> &mp,int start,int end,int *postIndex)
    {
        if(start>end) return NULL;
        TreeNode *root=new TreeNode(postorder[*postIndex]);
        int index=mp[postorder[*postIndex]];
        *postIndex=*postIndex-1;
        
        root->right=construct(postorder,mp,index+1,end,postIndex);
        root->left=construct(postorder,mp,start,index-1,postIndex);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        int postIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        return construct(postorder,mp,0,inorder.size()-1,&postIndex);
    }
};