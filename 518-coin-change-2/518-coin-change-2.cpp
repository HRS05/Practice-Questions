class Solution {
public:
    
    //tabulated code
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int> > dp(n,vector<int>(amount+1,0));
        
        for(int i=0;i<=amount;i++)
        {
            dp[0][i]=(i % coins[0] == 0);
        }
        
        
        for(int index=1;index<n;index++)
        {
            for(int tar=0;tar<=amount;tar++)
            {
                int notTake=dp[index-1][tar];
                int take=0;
                if(tar>=coins[index]) take=dp[index][tar-coins[index]];
                dp[index][tar]=take+notTake;
            }
        }
        return dp[n-1][amount];
    }
    
    
    /*
    //memoized code
    int getCount(int amount,vector<int> &coins,int index,vector<vector<int> > &dp)
    {
        if(amount==0) return 1;
        if(index<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=getCount(amount,coins,index-1,dp);
        int take=0;
        if(amount>=coins[index]) take=getCount(amount-coins[index],coins,index,dp);
        return dp[index][amount]=take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int> > dp(coins.size(),vector<int>(amount+1,-1));
        return getCount(amount,coins,coins.size()-1,dp);
    }
    */
    
    
    /*
    //recursive code
    int getCount(int amount,vector<int> &coins,int index)
    {
        if(amount==0) return 1;
        if(index<0) return 0;
        int notTake=getCount(amount,coins,index-1);
        int take=0;
        if(amount>=coins[index]) take=getCount(amount-coins[index],coins,index);
        return take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        return getCount(amount,coins,coins.size()-1);
    }
    */
};