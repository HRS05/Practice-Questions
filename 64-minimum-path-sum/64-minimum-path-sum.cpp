class Solution {
public:
    int pathSum(vector<vector<int> > &grid,int i,int j,vector<vector<int> > &dp)
    {
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right=INT_MAX;
        if(i>0) right=grid[i][j]+pathSum(grid,i-1,j,dp);
        int down=INT_MAX;
        if(j>0) down=grid[i][j]+pathSum(grid,i,j-1,dp);
        return dp[i][j]=min(right,down);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int> > dp(grid.size(),(vector<int>(grid[0].size(),-1)));
        return pathSum(grid,grid.size()-1,grid[0].size()-1,dp);
    }
};