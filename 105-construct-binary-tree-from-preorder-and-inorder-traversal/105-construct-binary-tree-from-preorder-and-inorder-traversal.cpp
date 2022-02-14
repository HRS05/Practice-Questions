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
    
    
    TreeNode* construct(vector<int> &preorder,int pi,int pj,vector<int> &inorder,int ii,int ij,map<int,int> &mp)
    {
        if(pi>pj || ii>ij) return NULL;
        
        TreeNode *root=new TreeNode(preorder[pi]);
        int index=mp[preorder[pi]];
        int x=index-ii;
        root->left=construct(preorder,pi+1,pi+x,inorder,ii,index-1,mp);
        root->right=construct(preorder,pi+x+1,pj,inorder,index+1,ij,mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode *node=construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return node;
    }
    
    /*
    int search(vector<int>& inorder,int start,int end,int curr)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==curr) return i;
        }
        return -1;
    }
    
    TreeNode * construction(vector<int>& preorder, vector<int>& inorder,int start,int end)
    {
        static int index=0;
        if(start>end) return NULL;
        int curr=preorder[index]; index++;
        TreeNode * node=new TreeNode(curr);
        if(start==end) return node;
        int pos=search(inorder,start,end,curr);
        node->left=construction(preorder,inorder,start,pos-1);
        node->right=construction(preorder,inorder,pos+1,end);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construction(preorder,inorder,0,inorder.size()-1);
    }
    */
};