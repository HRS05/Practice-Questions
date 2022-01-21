class Solution {
public:
    
    void check(vector<int> &nums,vector<int> &v,vector<vector<int> > &ans,int index)
    {
       ans.push_back(v);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            check(nums,v,ans,i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        check(nums,v,ans,0);
        
        return ans;
    }
    
    /*
    // this is brute force solution
    void check(vector<int> &nums,vector<int> &v,set<vector<int> > &s,int index)
    {
        if(index>=nums.size()){
            s.insert(v);
            return;
        }
        v.push_back(nums[index]);
        check(nums,v,s,index+1);
        v.pop_back();
        check(nums,v,s,index+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        set<vector<int> > s;
        sort(nums.begin(),nums.end());
        check(nums,v,s,0);
        for(auto it : s)
        {
            ans.push_back(it);
        }
        return ans;
    }
    */
};