class Solution {
public:
    int solve(int i,int j,vector<vector<int> > &dp,vector<int> &nums1,vector<int> &nums2)
    {
        int n=nums1.size();
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        
        for(int k=0;k<n;k++)
        {
            if((j & (1<<k)) == 0)
            {
                ans=min(ans,(nums1[i] ^ nums2[k]) + solve(i+1, j | (1<<k),dp,nums1,nums2));
            }
        }
        
        return dp[i][j]=ans;
        
    }
    
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int> > dp(n+1,vector<int>((1<<(n+1)),-1));
        return solve(0,0,dp,nums1,nums2);
    }
};