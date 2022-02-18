class Solution {
public:
    
    bool result(vector<int> &nums,int maxJumps,int index,vector<int> &dp)
    {
        if(index==nums.size()-1)return true;
        if(index>=nums.size())return false;
        if(dp[index]!=-1)return dp[index];
        for(int i=1;i<=maxJumps;i++)
        {
            if(result(nums,nums[index+i],index+i,dp)==true)return dp[index]=1;
        }
        return dp[index]=0;
    
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return result(nums,nums[0],0,dp);
    }
};