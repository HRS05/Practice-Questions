class Solution {
public:
    
    
    //space optimization
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int> curr(m+1,0),prev(m+1,0);
        if(n==0 && m==0) return 0;
        
        for(int i=1;i<=m;i++) prev[i]=i;        
        prev[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            curr[0]=i;
            for(int j=1;j<=m;j++)
            {
                int i1,i2,i3;
                i1=i2=i3=INT_MAX;
                if(s1[i-1]==s2[j-1])
                {
                    curr[j]=prev[j-1];
                    continue;
                }
                i1=1+prev[j-1];
                i2=1+prev[j];
                i3=1+curr[j-1];
                curr[j]=min({i1,i2,i3});
            }
            prev=curr;
        }
        return prev[m];
    }
    
    
    /*
    //tabulation 
    //TC : O(n*m)
    //SC : O(n*m)
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        if(n==0 && m==0) return 0;
        
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++) dp[0][i]=i;        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int i1,i2,i3;
                i1=i2=i3=INT_MAX;
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                    continue;
                }
                i1=1+dp[i-1][j-1];
                i2=1+dp[i-1][j];
                i3=1+dp[i][j-1];
                dp[i][j]=min({i1,i2,i3});
            }
        }
        return dp[n][m];
    }*/
    
    
    /*
    //recursive / memoized solution
    int f(string s1,int n,string s2,int m,vector<vector<int> > &dp)
    {
        if(m==0) return n;
        if(n==0) return m;
        int i1,i2,i3;
        if(dp[n][m]!=-1) return dp[n][m]; 
        i1=i2=i3=INT_MAX;
        if(s1[n-1]==s2[m-1]) return dp[n][m]=f(s1,n-1,s2,m-1,dp);
        i1=1+f(s1,n-1,s2,m-1,dp);
        i2=1+f(s1,n-1,s2,m,dp);
        i3=1+f(s1,n,s2,m-1,dp);
        return dp[n][m]=min({i1,i2,i3});
    }
    
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
        if(n==0 && m==0) return 0;
        return f(word1,n,word2,m,dp);
    }*/
};