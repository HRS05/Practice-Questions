class Solution {
public:
    int helper(vector<int> prices,int action,int index,vector<vector<int> > &dp)
    {
        int n=prices.size();
        if(index==n) return 0;
        int ans=0;
        if(dp[index][action]!=-1) return dp[index][action];
        if(action==1)
        {
            ans=max((-prices[index]+helper(prices,2,index+1,dp)),helper(prices,1,index+1,dp));
        }
        else if(action==2)
        {
            ans=max((prices[index]+helper(prices,3,index+1,dp)),helper(prices,2,index+1,dp));
        }
        else if(action==3)
        {
            ans=helper(prices,1,index+1,dp);
        }
        return dp[index][action]=ans;
    }
    
    
    int maxProfit(vector<int>& prices) {
        //buy=1 //sell=2 //cooldown=3
        int n=prices.size();
        vector<vector<int> > dp(n,vector<int>(4,-1));
        return helper(prices,1,0,dp);
    }
};