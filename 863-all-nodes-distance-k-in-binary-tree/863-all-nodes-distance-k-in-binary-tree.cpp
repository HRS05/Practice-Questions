/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> map;
        vector<int> ans;
        set<TreeNode*> s;
        populateMap(map,NULL,root);
        getNodesList(map,s,target,ans,k);
        return ans;   
    }
    
    
    void populateMap(unordered_map<TreeNode *,TreeNode *> &map,TreeNode *parent,TreeNode *curr)
{
  if(curr==NULL) return;
  map[curr]=parent;
  populateMap(map,curr,curr->left);
  populateMap(map,curr,curr->right);
  return;
}

void getNodesList(unordered_map<TreeNode *,TreeNode *> &map,set<TreeNode *> &s,TreeNode *currNode,vector<int> &ans,int k)
{
  if(currNode==NULL || s.find(currNode)!=s.end() || k<0) return;

s.insert(currNode);

  if(k==0){
    ans.push_back(currNode->val);
    return;  
  }

  getNodesList(map,s,currNode->left,ans,k-1);
  getNodesList(map,s,currNode->right,ans,k-1);
  getNodesList(map,s,map[currNode],ans,k-1);
  return;

}
    
    
};