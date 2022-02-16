class Solution {
public:
    
    
    //space optimize
    //TC : O(n*m*m*9)
    //SC : O(m*m)
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > prev(m,vector<int>(m,0));
        
        
        //initia..
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2) prev[j1][j2]=grid[n-1][j1];
                else prev[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            vector<vector<int> > curr(m,vector<int>(m,0));
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=-1e8;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int value=0;
                            if(j1==j2)
                                value=grid[i][j1];
                            else
                                value=grid[i][j1]+grid[i][j2];
                            if(j1+dj1<0 || j1+dj1>=m || j2+dj2<0 || j2+dj2>=m) 
                                value=-1e8;
                            else 
                                value+=prev[j1+dj1][j2+dj2];
                            maxi=max(maxi,value);
                        }
                    }
                    curr[j1][j2]=maxi;
                }
            }
            prev=curr;
        }
        return prev[0][m-1];
    }
    
    
    
    /*
    //tabulation
    //TC : O(n*m*m*9)
    //SC : O(n*m*m)
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> > rdp(m,vector<int>(m,0));
        vector<vector<vector<int> > > dp(n,rdp);
        
        //initia..
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=-1e8;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int value=0;
                            if(j1==j2)
                                value=grid[i][j1];
                            else
                                value=grid[i][j1]+grid[i][j2];
                            if(j1+dj1<0 || j1+dj1>=m || j2+dj2<0 || j2+dj2>=m) 
                                value=-1e8;
                            else 
                                value+=dp[i+1][j1+dj1][j2+dj2];
                            maxi=max(maxi,value);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
    */
    
    /*
    //memoized code
    //TC : O(n*m*m*9)
    //SC : O(n)+O(n*m*m)
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
    */
    
    
    /*
    //recursive code
    //TC : O(3^n * 3^n)
    //SC : O(n)
     int picking(vector<vector<int> > &grid,int i,int j1,int j2)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(j1>=m || j2>=m || j1<0 || j2<0) return -1e8;
        if(i==n-1)
        {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                if(j1==j2) maxi=max(maxi,grid[i][j1]+picking(grid,i+1,j1+dj1,j2+dj2));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+picking(grid,i+1,j1+dj1,j2+dj2));
            }
        }
        return maxi;    
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        return picking(grid,0,0,grid[0].size()-1); 
    }
    */
    
};