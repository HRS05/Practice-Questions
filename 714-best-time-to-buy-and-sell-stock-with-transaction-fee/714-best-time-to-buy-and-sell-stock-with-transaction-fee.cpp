class Solution {
public:
    
    int helper(int index,int action,int fee,vector<int> &prices,vector<vector<int> > &dp)
    {
        int n=prices.size();
        if(index==n) return 0;
        int ans;
        if(dp[index][action]!=-1) return dp[index][action];
        if(action==1)
        {
            ans=max((-prices[index]+helper(index+1,0,fee,prices,dp)),helper(index+1,action,fee,prices,dp));
        }
        else
        {
            ans=max((prices[index]+helper(index+1,1,fee,prices,dp)-fee),helper(index+1,action,fee,prices,dp));
        }
        return dp[index][action]=ans;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //sell=0 // buy=1
        vector<vector<int> > dp(n,vector<int>(2,-1));
        return helper(0,1,fee,prices,dp);
    }
};