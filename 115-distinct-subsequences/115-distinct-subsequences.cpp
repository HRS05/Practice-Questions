class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                long long count=0;
                if(s[i-1]==t[j-1]) count+=dp[i-1][j-1];
                count=count+dp[i-1][j];
                dp[i][j]=count;
            }
        }
        /*
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }  
        */
        return dp[n][m];
    }
    
    
    
/*
    //recursive / memoized solution
    int f(string s,int n,string t,int m,vector<vector<int> > &dp)
    {
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int count=0;
        
        if(s[n-1]==t[m-1]) count+=f(s,n-1,t,m-1,dp);
        count+=f(s,n-1,t,m,dp);
        return dp[n][m]=count;
    }    
    
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
        return f(s,n,t,m,dp);
    }
    */
};