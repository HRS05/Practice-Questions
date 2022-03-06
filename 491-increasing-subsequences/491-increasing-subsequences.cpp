class Solution {
public:
    
    void f(set<vector<int> > &s,vector<int> &nums,vector<int> &v,int index,int lastValue)
    {
        if(v.size()>=2) 
        {
            s.insert(v);
        }
        if(index>=nums.size()) return;
        if(lastValue<=nums[index])
        {
            v.push_back(nums[index]);
            f(s,nums,v,index+1,nums[index]);
            v.pop_back();
        }
        f(s,nums,v,index+1,lastValue);
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> >  ans;
        set<vector<int> > s;
        vector<int> v;
        f(s,nums,v,0,-101);
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};