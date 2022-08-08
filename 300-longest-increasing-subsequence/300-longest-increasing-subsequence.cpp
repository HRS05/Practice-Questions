class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] < nums[j])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
            //cout<<"ans -> "<<ans<<endl;
        }
        return ans;
    }
    
    
    /*
    //recursive solution
    int f(vector<int> &nums,int index,int lastNumber)
    {
        if(index>=nums.size()) return 0;
        int pick=0;
        int notPick=0;
        if(lastNumber < nums[index]) pick=1+f(nums,index+1,nums[index]);
        notPick=f(nums,index+1,lastNumber);
        return max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return f(nums,0,-10001);
    }
    */
};