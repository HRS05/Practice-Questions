class Solution {
public:
    
    void check(vector<vector<int> > &ans,map<int,bool> &mp,vector<int> v,int index)
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
                check(ans,mp,v,index);
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
        check(ans,mp,v,0);
        return ans;
    }
};