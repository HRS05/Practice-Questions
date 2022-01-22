class Solution {
public:
    
    
    void check(vector<vector<int> > &ans,vector<int> nums,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            int g=nums[index];
            nums[index]=nums[i];
            nums[i]=g;
            check(ans,nums,index+1);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        map<int,bool> mp;
        for(int it : nums){
            mp[it]=false;
        }
        check(ans,nums,0);
        return ans;
    }
    
    
    /*
    //T : O(n! * n)
    //S : O(n) + O(n)
    void check(vector<vector<int> > &ans,map<int,bool> &mp,vector<int> v)
    {
        if(v.size()==mp.size())
        {
            ans.push_back(v);
            return;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==false)
            {
                v.push_back(it->first);
                it->second=true;
                check(ans,mp,v);
                it->second=false;
                v.pop_back();
            }
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        map<int,bool> mp;
        for(int it : nums){
            mp[it]=false;
        }
        check(ans,mp,v);
        return ans;
    }
    */
};