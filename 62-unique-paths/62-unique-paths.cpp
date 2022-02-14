class Solution {
public:
    
    int uni(int m,int n,vector<vector<int> > &dp)
    {
       
        if(m<=0 || n<=0) return 0;
        if(n==1 && m==1) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int right,down;
        dp[m-1][n]=right=uni(m-1,n,dp);
        dp[m][n-1]=down=uni(m,n-1,dp);
        return dp[m][n]=right+down;
    }
    
    
    int uniquePaths(int m, int n) {
         vector<vector<int> > dp(m+1,vector<int>(n+1,-1));
        dp[0][0]=0;
        dp[1][1]=1;
        return uni(m,n,dp);
    }
};