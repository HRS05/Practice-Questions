class Solution {
public:
    
    int picking(vector<vector<int> > &grid,int i,int j1,int j2,vector<vector<vector<int>>> &dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j1>=m || j2>=m || j1<0 || j2<0) return -1e8;
        if(i==n-1)
        {
            if(j1==j2) 
            {
                return dp[i][j1][j2]=grid[i][j1];
            }
            else 
            {
                return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                if(j1==j2) maxi=max(maxi,grid[i][j1]+picking(grid,i+1,j1+dj1,j2+dj2,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+picking(grid,i+1,j1+dj1,j2+dj2,dp));
            }
        }
        return dp[i][j1][j2]=maxi;    
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > rdp(m,vector<int>(m,-1));
        vector<vector<vector<int> > > dp(n,rdp);
        return picking(grid,0,0,grid[0].size()-1,dp); 
    }
};