class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        for(int i=1;i<=m;i++)
        {
            int flag=true;
            for(int ii=1;ii<=i;ii++)
            {
                if(p[ii-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][i]=flag;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?') 
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*') 
                {
                    bool i1=dp[i-1][j]; //considering that p contains sequence in s
                    bool i2=dp[i][j-1]; //considering that '*' in p contains empty sequence in s
                    dp[i][j]=(i1 || i2);
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
    
    /*
    // recursive and memoized solution 
    //TLE
    bool f(string s,int n,string p,int m,vector<vector<int> > &dp)
    {
        if(n>=0 && m>=0 && dp[n][m]!=-1) return dp[n][m];
        if(n==0 && m==0) return dp[0][0]=true;
        if(m==0) return dp[n][m]=false;
        if(n==0)
        {
            for(int i=m;i>=1;i--)
            {
                if(p[i-1]!='*') return dp[n][m]=false;
            }
            return dp[n][m]=true;
        }
        
        //if(n==0)
        if(s[n-1]==p[m-1] || p[m-1]=='?') return dp[n][m]=f(s,n-1,p,m-1,dp);
        else if(p[m-1]=='*') {
            bool i1=f(s,n-1,p,m,dp); //considering that p contains sequence in s
            bool i2=f(s,n,p,m-1,dp); //considering that '*' in p contains empty sequence in s
            return dp[n][m]=(i1 || i2);
        }
        return dp[n][m]=false;
            
    }
    
    
    bool isMatch(string s, string p) 
    {
        int n=s.size();
        int m=p.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
        return f(s,n,p,m,dp);
    }
    */
};