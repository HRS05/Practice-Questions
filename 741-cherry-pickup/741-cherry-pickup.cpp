class Solution {
public:
    
    int helper(vector<vector<int> > &grid,int r1,int c1,int c2,vector<vector<vector<int> > > &dp)
    {
        int n=grid.size();
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
       
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        
        int ans=grid[r1][c1];
        if(r1!=r2) ans+=grid[r2][c2];
        
        int dummy=max(max(helper(grid,r1,c1+1,c2+1,dp),helper(grid,r1+1,c1,c2,dp)),max(helper(grid,r1+1,c1,c2+1,dp),helper(grid,r1,c1+1,c2,dp)));
        ans+=dummy;
        dp[r1][c1][c2]=ans;
        return ans;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int> > >  dp(n,vector<vector<int> >(n,vector<int>(n,-1)));
        
        return max(0,helper(grid,0,0,0,dp));
    }
};