class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // we have to calulate longest bitonic subsequence length(maxi) and return n-maxi
        int n=nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev] < nums[i] && 1+dp1[prev] > dp1[i])
                {
                    dp1[i]=1+dp1[prev];
                }
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=n-1;prev>i;prev--)
            {
                if(nums[prev] < nums[i] && 1+dp2[prev] > dp2[i])
                {
                    dp2[i]=1+dp2[prev];
                }
            }
        }
        
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            //in this specific question we are only considering the increasing as well as
            //also decreasing part of bitonic sequence (because of array mountain)
            //this below condition will avoid the only increasing and only decreasing cases
            if(dp1[i] > 1 && dp2[i] > 1)
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        
        return n-maxi;
    }
};