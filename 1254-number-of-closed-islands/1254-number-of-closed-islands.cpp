class Solution {
public:
    
    bool check(vector<vector<int> > &grid,int r,int c)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m) return false;
        if(grid[r][c] == 2) return true;
        if(grid[r][c]==1) return true; 
        if(grid[r][c]==3) return false;
        grid[r][c]=2;
        bool ans=true;
        ans=ans && check(grid,r+1,c);
        ans=ans && check(grid,r-1,c);
        ans=ans && check(grid,r,c+1);
        ans=ans && check(grid,r,c-1);
        if(!ans) grid[r][c]=3;
        return ans;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0 && check(grid,i,j)){
                    cout<<i<<"  "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};