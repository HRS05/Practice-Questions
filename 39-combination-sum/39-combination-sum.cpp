class Solution {
public:
    
    void check(vector<vector<int>> &ans,vector<int>& candidates,vector<int> &v,int target,int index)
    {
        if(index>=candidates.size()) 
        {
            if(target==0) ans.push_back(v); 
            return;
        }
        if(target<0) return;
        v.push_back(candidates[index]);
        check(ans,candidates,v,target-candidates[index],index);
        v.pop_back();
        check(ans,candidates,v,target,index+1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        check(ans,candidates,v,target,0);
        return ans;
    }
};