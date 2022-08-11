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

class Data {
  public :
    int maxSum;
    int maxValue;
    int minValue;
    bool isBST;
    Data()
    {
        maxSum=0;
        maxValue=INT_MIN;
        minValue=INT_MAX;
        isBST=true;
    }
};

class Solution {
public:
    
    Data* helper(TreeNode *root,int &ans)
    {
        Data *data=new Data();
        if(root==NULL) return data;
        
        Data *leftData=helper(root->left,ans);
        Data *rightData=helper(root->right,ans);
        
        if(leftData->isBST && rightData->isBST && leftData->maxValue < root->val && rightData->minValue > root->val)
        {
            data->isBST=true;
            data->maxSum=leftData->maxSum+rightData->maxSum+root->val;
            data->maxValue=max(root->val,rightData->maxValue);
            data->minValue=min(root->val,leftData->minValue);
        }
        else
        {
            data->isBST=false;
            data->maxSum=max(leftData->maxSum,rightData->maxSum);
        }
        ans=max(ans,data->maxSum);
        return data;
    }
    
    
    int maxSumBST(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};

/*
class Solution {
public:
    
    bool checkIsBST(TreeNode *root,TreeNode *&prev,int &sum)
    {
        if(root==NULL) return true;
        bool lcheck=checkIsBST(root->left,prev,sum);
        if(prev)
        {
            if(prev->val < root->val) sum+=root->val;
            else {
                sum=0;
                return false;
            }
        }
        else
        {
            sum+=root->val;
        }
        prev=root;
        bool check = lcheck && checkIsBST(root->right,prev,sum);
        if(!check) {
            sum=0;
            return false;
        } 
        return true;
    }
    
    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode *prev=NULL;
        int ans=0;
        checkIsBST(root,prev,ans);
        int lh=0,rh=0;
        lh=maxSumBST(root->left);
        rh=maxSumBST(root->right);
        return max({ans,lh,rh});
    }
};*/