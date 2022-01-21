class Solution {
public:
    
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
};