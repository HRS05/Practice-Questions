class Solution {
public:
    
    int result(vector<int> &nums,int maxJumps,int index,vector<int> &dp)
    {
        if(index==nums.size()-1) return 0;
        if(index>=nums.size()) return 1e8;
        int minJumps=1e8;
        if(dp[index]!=-1) return dp[index]; 
        for(int i=1;i<=maxJumps;i++)
        {
            int j=1e8;
            if(index+i<nums.size())j=result(nums,nums[index+i],index+i,dp)+1;
            minJumps=min(minJumps,j);
        }
        return dp[index]=minJumps;
    }
 
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return result(nums,nums[0],0,dp);
    }
};