class Solution {
public:
    int helper(vector<int> &nums,int n,bool isUp,vector<vector<int> > &dp)
    {
        int maxCount = 0;
        if(dp[n][isUp]!=-1) return dp[n][isUp];
        for(int i=n+1;i<nums.size();i++)
        {
            if((isUp && nums[i] > nums[n]) || (!isUp && nums[i] < nums[n]))
                maxCount=max(maxCount,1+helper(nums,i,!isUp,dp));
        }
        return dp[n][isUp]=maxCount;
    }
    
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<vector<int> > dp(nums.size(),vector<int>(2,-1));
        return 1 + max(helper(nums,0,true,dp),helper(nums,0,false,dp));
    }
};