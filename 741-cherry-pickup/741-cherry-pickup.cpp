class Solution {
public:
    /*
    //iterative solution
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int> > >  dp(n,vector<vector<int> >(n,vector<int>(n,-1)));
        int r1,c1,c2;
        for(int r1=0)
        
        
        return max(0,helper(grid,0,0,0,dp));
    }
    */
    
    
    //recursive and memoized code
    //top down solution
    int helper(vector<vector<int> > &grid,int r1,int c1,int c2,vector<vector<vector<int> > > &dp)
    {
        int n=grid.size();
        int r2=r1+c1-c2;
        if(r1<0 || r2<0 || c1<0 || c2<0 || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
       
        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];
        
        if(r1==0 && c1==0) return grid[r1][c1];
        
        int ans=grid[r1][c1];
        if(r1!=r2) ans+=grid[r2][c2];
        
        int dummy=max(max(helper(grid,r1,c1-1,c2-1,dp),helper(grid,r1-1,c1,c2,dp)),max(helper(grid,r1-1,c1,c2-1,dp),helper(grid,r1,c1-1,c2,dp)));
        ans+=dummy;
        dp[r1][c1][c2]=ans;
        return ans;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int> > >  dp(n,vector<vector<int> >(n,vector<int>(n,-1)));
        
        return max(0,helper(grid,n-1,n-1,n-1,dp));
    }
};