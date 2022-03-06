class Solution {
public:
    
    //tabulation code
    long long mode=1e9+7;
    int countOrders(int n) {
        vector<vector<long> > dp(n+1,vector<long>(n+1,0));
        
        for(int ps=0;ps<=n;ps++)
        {
            for(int ds=0;ds<=n;ds++)
            {
                if(ds==0 && ps==0) 
                {
                    dp[0][0]=1;
                    continue;
                }
                if(ps>0) dp[ps][ds] += ps*dp[ps-1][ds];
                dp[ps][ds]%=mode;
                
                if(ds>ps) dp[ps][ds] += (ds-ps) * dp[ps][ds-1];
                dp[ps][ds]%=mode;
            }
        }
        return dp[n][n];
    }
    
    
    /*
    //recursive+memoized solution
    long long mode=1e9+7;
    long long f(int ps,int ds,vector<vector<int> > &dp)
    {
        if(ps==0 && ds==0)
        {
            return 1;
        }
        if(ps<0 || ds<0 || ds<ps)
        {
            return 0;
        }
        if(dp[ps][ds]!=-1) return dp[ps][ds];
        long long ans=0;
        ans+=ps * f(ps-1,ds,dp);
        ans%=mode;
        ans+=(ds-ps) * f(ps,ds-1,dp);
        ans%=mode;
        
        return dp[ps][ds]=(int) ans;
    }
    
    
    int countOrders(int n) {
        vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
        return f(n,n,dp);
    }
    */
    
    /*
    //math solution
    int countOrders(int n) {
        
        long long mode=1e9+7;
        long long ans=1;
        
        for(int i=2;i<=n;i++)
        {
            int spaceCount=(i-1)*2+1;
            ans*=spaceCount*(spaceCount+1)/2;
            ans=ans%(mode);
        }
        return (int)ans;
    }
    */
};
