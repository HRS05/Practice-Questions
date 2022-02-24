class Solution {
public:
    
    int f(vector<int> &coins,int amount,int index,vector<vector<int> > &dp)
    {
        if(amount==0)
        {
            return 0;
        }
        if(index<0 || amount<0)
        {
            return 1e8;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake=0+f(coins,amount,index-1,dp);
        int take=1e8;
        if(coins[index]<=amount)
        {
            take=1+f(coins,amount-coins[index],index,dp);
        }
        return dp[index][amount]=min(take,notTake);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> > dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins,amount,coins.size()-1,dp);
        if(ans>amount) return -1;
        return ans;
    }
};