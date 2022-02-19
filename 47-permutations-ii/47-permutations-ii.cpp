class Solution {
public:
    
    //optimise solution
    void check(vector<vector<int> > &ans,vector<int> &nums,int pos)
    {
        if(pos==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++)
        {
            if(i > pos && nums[i]==nums[pos]) continue;
            swap(nums[i],nums[pos]);
            check(ans,nums,pos+1);
        }
        //restoring all swaps
        for (int i = nums.size() - 1; i > pos; --i) {
                swap(nums[pos], nums[i]);
            }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        check(ans,nums,0);
        return ans;
    }
    
    
    /*
    //also solve it using mapfor hashing
    //TC : O(n!)
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
    */
};