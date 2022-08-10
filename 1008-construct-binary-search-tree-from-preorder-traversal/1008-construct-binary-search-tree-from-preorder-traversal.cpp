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
    
    TreeNode *construct(vector<int> &preorder,int i,int f)
    {
        if(i > f) return NULL;
        TreeNode *node=new TreeNode(preorder[i]);
        int j;
        for(j=i+1;j<=f;j++){
            if(preorder[i]<preorder[j]) break;
        }
        node->left=construct(preorder,i+1,j-1);
        node->right=construct(preorder,j,f);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder,0,preorder.size()-1);
    }
    
//     TreeNode* construct(vector<int> &inorder,int inStart,int inEnd,vector<int> &preorder,int preStart,int preEnd,map<int,int> &mp)
//     {
//         if(inStart > inEnd || preStart > preEnd) return NULL;
//         TreeNode *node=new TreeNode(preorder[preStart]);
//         int index=mp[preorder[preStart]];
//         int factor=inStart-index;
//         node->left=construct(inorder,inStart,index-1,preorder,preStart+1,preStart+factor,mp);
//         node->right=construct(inorder,index+1,inEnd,preorder,preStart+factor+1,preEnd,mp);
//         return node;
//     }
     
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         vector<int> inorder=preorder;
//         sort(inorder.begin(),inorder.end());
//         map<int,int> mp;
//         for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
//         return construct(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,mp);
//     }
};