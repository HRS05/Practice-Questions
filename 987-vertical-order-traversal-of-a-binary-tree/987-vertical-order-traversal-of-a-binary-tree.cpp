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
    
    void getVerticleData(map<int,map<int,vector<int> > > &data,TreeNode *root,int hIndex,int dIndex)
    {
        if(root==NULL) return;
        data[hIndex][dIndex].push_back(root->val);
        getVerticleData(data,root->left,hIndex-1,dIndex+1);
        getVerticleData(data,root->right,hIndex+1,dIndex+1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int> > ans;
        map<int,map<int,vector<int> > > data;
        getVerticleData(data,root,0,0);
        for(pair<int,map<int,vector<int> > > p : data)
        {
            vector<int> v;
            for(pair<int,vector<int> > x : p.second)
            {
                sort(x.second.begin(),x.second.end());
                v.insert(v.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};