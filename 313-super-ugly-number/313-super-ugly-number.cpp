class Solution {
public:
    int getMin(vector<int> &primes,vector<int> &pointers,vector<int> &dp)
    {
        int mini=INT_MAX;
        for(int i=0;i<pointers.size();i++)
        {
            long x=(long)dp[pointers[i]]*primes[i];
            if(mini>x)
            {
                mini=x;
            }
        }
        for(int i=0;i<pointers.size();i++)
        {
            long x=(long)dp[pointers[i]]*primes[i];
            if(mini == x)   pointers[i]++;
        }
        return mini;
    }
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1,1);
        dp[0]=1;
        vector<int> pointers(primes.size(),0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=getMin(primes,pointers,dp);
        }
        return dp[n-1];
    }
};