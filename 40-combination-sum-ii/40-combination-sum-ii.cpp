class Solution {
public:
    
    void check(vector<vector<int>> &ans,vector<int>& candidates,vector<int> &v,int target,int index)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            check(ans,candidates,v,target-candidates[i],i+1);
            v.pop_back();           
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        check(ans,candidates,v,target,0);
       
        return ans;
    }
    
    
    /*
    //this is brute force solution inspired by problem Combination Sum
    // time complexity : O(2^k * k * log(k))
    void check(set<vector<int>> &s,vector<int>& candidates,vector<int> &v,int target,int index)
    {
        if(index>=candidates.size()) 
        {
            if(target==0) {
                s.insert(v); 
            }
            return;
        }
        if(target<0) return;
        v.push_back(candidates[index]);
        check(s,candidates,v,target-candidates[index],index+1);
        v.pop_back();
        check(s,candidates,v,target,index+1);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        set<vector<int> > s;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        check(s,candidates,v,target,0);
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
    */
};