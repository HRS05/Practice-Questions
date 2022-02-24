class Solution {
public:
    
    //tabulation code
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int> > dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++) 
        {
            if(i % coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e8;    
        }
        for(int i=1;i<n;i++)
        {
            for(int tar=0;tar<=amount;tar++)
            {
                int notTake=0+dp[i-1][tar];
                int take=1e8;
                if(coins[i]<=tar)
                {
                    take=1+dp[i][tar-coins[i]];
                }
                dp[i][tar]=min(take,notTake);
            }
        }
        
        return dp[n-1][amount] > amount ? -1 : dp[n-1][amount];
    }
    
    /*
    //memoized code
    //TC : O(n*amount)
    //SC : >>> O(n*amount) + O(amount)
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
    */
    
    
    /*
    //recursive code
    //TC : >>> O(2^n)
    //SC : >>> O(amount)
     int f(vector<int> &coins,int amount,int index)
    {
        if(amount==0)
        {
            return 0;
        }
        if(index<0 || amount<0)
        {
            return 1e8;
        }
        
        int notTake=0+f(coins,amount,index-1);
        int take=1e8;
        if(coins[index]<=amount)
        {
            take=1+f(coins,amount-coins[index],index);
        }
        return min(take,notTake);
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int ans=f(coins,amount,coins.size()-1);
        if(ans>amount) return -1;
        return ans;
    }
    */
};