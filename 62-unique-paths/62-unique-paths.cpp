class Solution {
public:
    
    int uni(int m,int n,vector<vector<int> > &dp)
    {
       
        if(m<=0 || n<=0) return 0;
        if(n==1 && m==1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int right,down;
        right=uni(m-1,n,dp);
        down=uni(m,n-1,dp);
        return dp[m][n]=right+down;
    }
    
    
    int uniquePaths(int m, int n) {
         vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 && j==1) dp[i][j]=1;
                else
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
    
    
    
    /*
    //memoized code
    int uni(int m,int n,vector<vector<int> > &dp)
    {
       
        if(m<=0 || n<=0) return 0;
        if(n==1 && m==1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int right,down;
        right=uni(m-1,n,dp);
        down=uni(m,n-1,dp);
        return dp[m][n]=right+down;
    }
    
    
    int uniquePaths(int m, int n) {
         vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=0;
        dp[1][1]=1;
        return uni(m,n,dp);
    }
    */
};