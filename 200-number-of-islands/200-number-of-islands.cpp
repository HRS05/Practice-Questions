class Solution {
public:
    
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return;
        if(grid[x][y]=='0') return;
        //vis[x][y]=true;
        grid[x][y]='0';
        dfs(x-1,y,grid);
        dfs(x,y-1,grid);
        dfs(x+1,y,grid);
        dfs(x,y+1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        //vector<vector<bool> > vis(n,vector<bool>(m,false));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};