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
    
    int robbing(TreeNode *root,int &robMax,int &notRobMax)
    {
        if(root==0) return 0;
        int leftRobMax=0,leftNotRobMax=0;
        int rightRobMax=0,rightNotRobMax=0;
        int leftMax=robbing(root->left,leftRobMax,leftNotRobMax);
        int rightMax=robbing(root->right,rightRobMax,rightNotRobMax);
        robMax=root->val+leftNotRobMax+rightNotRobMax;
        notRobMax=leftMax+rightMax;
        
        return max(robMax,notRobMax);
        
    }
    
    
    int rob(TreeNode* root) {
        int robMax=0;
        int notRobMax=0;
        return robbing(root,robMax,notRobMax);
    }
    
    
    /*
    int getMaxCount(TreeNode* root,map<TreeNode *,int> &mp)
    {
        if(root==NULL) return 0;
        if(mp.find(root)!=mp.end()) return mp.find(root)->second;
        int sum=0;
        sum=sum+root->val;
        if(root->left!=NULL)
        {
            sum+=getMaxCount(root->left->left,mp);
            sum+=getMaxCount(root->left->right,mp);
        }
        if(root->right!=NULL)
        {
            sum+=getMaxCount(root->right->left,mp);
            sum+=getMaxCount(root->right->right,mp);
        }
        return mp[root]=max(sum,(getMaxCount(root->left,mp)+getMaxCount(root->right,mp)));
    }
    
    
    int rob(TreeNode* root) {
        map<TreeNode *,int> mp;
        return getMaxCount(root,mp);
    }
    */
};