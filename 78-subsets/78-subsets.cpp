class Solution {
public:
    
    void check(vector<int> &nums,vector<int> &v,vector<vector<int> > &ans,int index)
    {
        if(index>=nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        check(nums,v,ans,index+1);
        v.pop_back();
        check(nums,v,ans,index+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> v;
        check(nums,v,ans,0);
        return ans;
    }
};