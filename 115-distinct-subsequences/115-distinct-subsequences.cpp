class Solution {
public:
    //1 D Array space optimization
    //TC : O(n*m)
    //SC : O(m)
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<double> curr(m+1,0);
        
        curr[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                long long count=0;
                if(s[i-1]==t[j-1]) curr[j]=curr[j-1]+curr[j];//count+=curr[j-1];
                //curr[j]=count+curr[j];
            }
        }
        
        return (int)curr[m];
    }
    
    /*
    //TC : O(n*m)
    //SC : O(m)
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        
        vector<int> prev(m+1,0),curr(m+1,0);
        
        prev[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                long long count=0;
                if(s[i-1]==t[j-1]) count+=prev[j-1];
                count=count+prev[j];
                curr[j]=count;
            }
            prev=curr;
        }
        
        return prev[m];
    }
    */
    
    
    /*
    //tabulation code
    //TC : O(n*m)
    //SC : O(n*m)
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
        
        return dp[n][m];
    }
    */
    
    
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