class Solution {
public:
    
    int f(vector<int>& nums, int target,vector<int> &dp)
    {
        int count=0;
        if(target==0){
             return 1;
        }
        if(dp[target]!=-1) return dp[target];
       
        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[i] >= 0) {
                count+=f(nums,target-nums[i],dp);
            }
            
        }
        return dp[target]=count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(1001,-1);
        return f(nums,target,dp);
    }
};