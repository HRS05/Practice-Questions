class Solution {
public:
    
    //space optimization
    bool canPartition(vector<int>& nums) 
    {   
        int totalSum=0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        if(totalSum%2!=0) return false;
        totalSum=totalSum/2;
        
        vector<bool> prev(totalSum+1,false);
        
        prev[0]=true;
            
        if(totalSum>=nums[0])prev[nums[0]]=true;
        
        for(int i=1;i<nums.size();i++)
        {
            vector<bool> curr(totalSum+1);
            for(int target=1;target<=totalSum;target++)
            {
                bool notTake=prev[target];
                bool take=false;
                if(target>=nums[i]) take=prev[target-nums[i]];  
                curr[target]=take || notTake; 
            }
            prev=curr;
        }
        return prev[totalSum];
    }
    
    /*
    //tabulation code
    bool canPartition(vector<int>& nums) 
    {   
        int totalSum=0;
        for(int i=0;i<nums.size();i++) totalSum+=nums[i];
        if(totalSum%2!=0) return false;
        totalSum=totalSum/2;
        
        vector<vector<bool> > dp(nums.size(),vector<bool>(totalSum+1,false));
        
        for(int i=0;i<nums.size();i++) dp[i][0]=true;  
            
        if(totalSum>=nums[0])dp[0][nums[0]]=true;
        
        for(int i=1;i<nums.size();i++)
        {
            for(int target=1;target<=totalSum;target++)
            {
                bool notTake=dp[i-1][target];
                bool take=false;
                if(target>=nums[i]) take=dp[i-1][target-nums[i]];  
                dp[i][target]=take || notTake; 
            }
        }
        return dp[nums.size()-1][totalSum];
    }
    */
    
    
    /*
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
    */
    
    
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