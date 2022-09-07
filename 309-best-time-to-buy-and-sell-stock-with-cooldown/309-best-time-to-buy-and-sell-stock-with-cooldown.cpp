class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy=1 //sell=2 //cooldown=3
        int n=prices.size();
        vector<vector<int> > dp(n+1,vector<int>(4,0));
        
        for(int index=n-1;index>=0;index--)
        {
            for(int action=1;action<=3;action++)
            {
                if(action==1)
                {
                    dp[index][action]=max((-prices[index]+dp[index+1][2]),dp[index+1][1]);
                    //ans=max((-prices[index]+helper(prices,2,index+1,dp)),helper(prices,1,index+1,dp));
                }
                else if(action==2)
                {
                    dp[index][action]=max((prices[index]+dp[index+1][3]),dp[index+1][2]);
                    //ans=max((prices[index]+helper(prices,3,index+1,dp)),helper(prices,2,index+1,dp));
                }
                else if(action==3)
                {
                    dp[index][action]=dp[index+1][1];
                    //ans=helper(prices,1,index+1,dp);
                }
            }
        }
        
        return dp[0][1];
    }
    
    
    /*
    //recursive and memoized solution
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
    */
};