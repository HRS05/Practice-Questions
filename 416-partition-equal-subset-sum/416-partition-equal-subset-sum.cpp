class Solution {
public:
    
    
    //memoized code
    bool checkTarget(vector<int> &nums,int index,int target,vector<vector<int> > &dp)
    {
        if(target==0) return true;
        if(index<0 || target<0) return false;
        if(index==0) return (nums[0]==target);
        if(dp[index][target]!=-1) return dp[index][target];
        bool notTake=checkTarget(nums,index-1,target,dp);
        bool take=checkTarget(nums,index-1,target-nums[index],dp);
        return dp[index][target]=take || notTake; 
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int totalSum=0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        if(totalSum%2!=0) return false;
        totalSum=totalSum/2;
        
        vector<vector<int> > dp(nums.size(),vector<int>(totalSum+1,-1));
        
        return checkTarget(nums,nums.size()-1,totalSum,dp);
        
    }
    
    
    
    /*
    //recursive code
    //TC : O(2^n)
    bool checkTarget(vector<int> &nums,int index,int target)
    {
        if(index<0) return false;
        if(nums[index]==target) return true;
        bool notTake=checkTarget(nums,index-1,target);
        bool take=checkTarget(nums,index-1,target-nums[index]);
        return take || notTake; 
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int totalSum=0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        if(totalSum%2!=0) return false;
        totalSum=totalSum/2;
        return checkTarget(nums,nums.size()-1,totalSum);
        
    }
    */
};