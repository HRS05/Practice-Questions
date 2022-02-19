class Solution {
public:
    
    void check(set<vector<int> > &s,vector<int> &v,vector<int> &nums,vector<bool> &vis)
    {
        if(v.size()==nums.size())
        {
            s.insert(v);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                v.push_back(nums[i]);
                check(s,v,nums,vis);
                vis[i]=false;
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        vector<bool> vis(nums.size(),false);
        set<vector<int> > s;
        check(s,v,nums,vis);
        for(auto it=s.begin();it!=s.end();it++) ans.push_back(*it);
        return ans;
    }
};