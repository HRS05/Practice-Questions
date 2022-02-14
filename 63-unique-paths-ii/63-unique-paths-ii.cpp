class Solution {
public:
    
    //memoized code
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
};