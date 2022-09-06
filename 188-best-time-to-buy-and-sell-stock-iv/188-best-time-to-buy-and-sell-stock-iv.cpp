class Solution {
public:
    
    //tabulation code
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int> > > dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=k;cap++)
                {
                     if(buy)
                    {
                        dp[index][buy][cap]=max((-prices[index]+dp[index+1][0][cap]),dp[index+1][1][cap]);
                        //dp[index][buy][cap]=max((-prices[index]+helper(prices,index+1,0,cap,dp)),helper(prices,index+1,1,cap,dp));
                    }
                    else
                    {
                        dp[index][buy][cap]=max((prices[index]+dp[index+1][1][cap-1]),dp[index+1][0][cap]);
                        //dp[index][buy][cap]=max((prices[index]+helper(prices,index+1,1,cap-1,dp)),helper(prices,index+1,0,cap,dp));
                    }
                    
                }
            }
        }
        
        return dp[0][1][k];
    }
    
    
    
    /*
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
    
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int> > > dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(prices,0,1,k,dp);
    }
    */
};