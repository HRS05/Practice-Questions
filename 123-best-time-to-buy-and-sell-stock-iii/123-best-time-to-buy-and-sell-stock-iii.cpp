class Solution {
public: 
    int helper(vector<int> &prices,int index,int buy,int cap,vector<vector<vector<int> > > &dp)
    {
        int n=prices.size();
        if(cap==0 || index==n) return 0;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if(buy)
        {
            dp[index][buy][cap]=max((-prices[index]+helper(prices,index+1,0,cap,dp)),helper(prices,index+1,1,cap,dp));
        }
        else
        {
            dp[index][buy][cap]=max((prices[index]+helper(prices,index+1,1,cap-1,dp)),helper(prices,index+1,0,cap,dp));
        }
        return dp[index][buy][cap];
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,0,1,2,dp);
    }
};