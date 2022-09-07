class Solution {
public:
    
    //tabulation code and space optimization
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        //sell=0 // buy=1
        vector<int> after(2,0);
        vector<int> curr(2,0);
        
        for(int index=n-1;index>=0;index--)
        {
            for(int action=0;action<2;action++)
            {
                if(action==1)
                {
                    curr[action]=max((-prices[index]+after[0]),after[action]);
                    //ans=max((-prices[index]+helper(index+1,0,fee,prices,dp)),helper(index+1,action,fee,prices,dp));
                }
                else
                {
                    curr[action]=max((prices[index]+after[1]-fee),after[action]);
                    //ans=max((prices[index]+helper(index+1,1,fee,prices,dp)-fee),helper(index+1,action,fee,prices,dp));
                }   
            }
            after=curr;
        }
        
        return after[1];
    }
    
    
    
    /*
    //tabulation code
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        //sell=0 // buy=1
        vector<vector<int> > dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int action=0;action<2;action++)
            {
                if(action==1)
                {
                    dp[index][action]=max((-prices[index]+dp[index+1][0]),dp[index+1][action]);
                    //ans=max((-prices[index]+helper(index+1,0,fee,prices,dp)),helper(index+1,action,fee,prices,dp));
                }
                else
                {
                    dp[index][action]=max((prices[index]+dp[index+1][1]-fee),dp[index+1][action]);
                    //ans=max((prices[index]+helper(index+1,1,fee,prices,dp)-fee),helper(index+1,action,fee,prices,dp));
                }   
            }
        }
        
        return dp[0][1];
    }
    */
    
    
    /*
    //recursive and memoized solution
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
    */
};