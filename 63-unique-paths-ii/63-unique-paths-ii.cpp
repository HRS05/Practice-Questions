class Solution {
public:
    //space optimization
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<int> prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int> tmp(n,0);
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) 
                {    
                    tmp[j]=0;
                    continue;
                }
                if(i==0 && j==0) tmp[j]=1;
                else
                {
                    tmp[j]=(j>0 ? tmp[j-1] : 0)+prev[j];
                }
            }
            prev=tmp;
        }
        return prev[n-1];
    }
    
    /*
    //tabulation code
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1) 
                {    
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) dp[i][j]=1;
                else
                {
                    dp[i][j]=( j>0 ? dp[i][j-1] : 0 )+( i>0 ? dp[i-1][j] : 0);
                }
            }
        }
        return dp[m-1][n-1];
    }
    */
    
    //memoized code
    /*
    int uni(int m,int n,vector<vector<int> > &dp,vector<vector<int>>& obstacleGrid)
    {
        if(m>=0 && n>=0 && obstacleGrid[m][n]==1) return 0;
        if(m<0 || n<0) return 0;
        if(n==0 && m==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        int right,down;
        right=uni(m-1,n,dp,obstacleGrid);
        down=uni(m,n-1,dp,obstacleGrid);
        return dp[m][n]=right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        dp[0][0]=1;
        return uni(obstacleGrid.size()-1,obstacleGrid[0].size()-1,dp,obstacleGrid);
    }
    */
};