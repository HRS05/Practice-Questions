class Solution {
public:
    
    
    //tabulation code
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int take;
            if(i-2 >= 0)take=nums[i]+dp[i-2];
            else take=nums[i];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
    
    
    /*
    // memoization code
    int solve(int index,vector<int> &nums,vector<int> &dp)
    {
        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1)  return dp[index]; 
        int pick=nums[index]+solve(index-2,nums,dp);
        int notPick=solve(index-1,nums,dp);
        return dp[index]=max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(),-1);
        return solve(n-1,nums,dp);
    }
    */
    
    /*
    //another recursive solution
    // TLE 
    int solve(int index,vector<int> &nums)
    {
        if(index==0) return nums[index];
        if(index<0) return 0;
        int pick=nums[index]+solve(index-2,nums);
        int notPick=solve(index-1,nums);
        return max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(n-1,nums);
    }
    */
    
    /*
    //recursive code
    //TLE
    void solve(vector<int> &nums,int sum,int *maxSum,int index)
    {
        if(index>=nums.size())
        {
            if(sum > *maxSum) *maxSum=sum;
            return;
        }
        solve(nums,sum+nums[index],maxSum,index+2);
        solve(nums,sum,maxSum,index+1);
        
    }
    
    int rob(vector<int>& nums) {
        int sum=0;
        int maxSum=0;
        solve(nums,sum,&maxSum,0);
        return maxSum;
    }
    */
};