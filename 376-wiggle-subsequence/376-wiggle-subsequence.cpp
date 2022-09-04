class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> up(nums.size());
        vector<int> down(nums.size());
        up[0]=down[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > nums[i-1])
            {
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1])
            {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            }
            else
            {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        
        return max(down[nums.size()-1],up[nums.size()-1]);
    }
    
    
    /*
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> up(nums.size());
        vector<int> down(nums.size());
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i] > nums[j]) up[i]=max(up[i],down[j]+1);
                else if(nums[i] < nums[j]) down[i]=max(down[i],up[j]+1);
            }
        }
        
        return 1 + max(down[nums.size()-1],up[nums.size()-1]);
    }
    */
    
    
    /*
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
    */
};