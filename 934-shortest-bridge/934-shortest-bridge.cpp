class Solution {
public:
    int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isValid(int i,int j,vector<vector<bool> > &vis)
    {
        int n=vis.size();
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j]) return false;
        return true;
    }
    
    void dfs(int i,int j,vector<vector<int> > &grid,vector<vector<bool> > &vis,queue<pair<int,int> > &q)
    {
         vis[i][j] = 1;
        q.push({i,j});     // pushing all points of island 1 so that we can measure the distance from all                               //the points
        for(int k=0;k<4;k++)
        {
            int r = i+dxy[k][0];
            int c = j+dxy[k][1];
            if(isValid(r,c,vis) && grid[r][c])
            {
                dfs(r,c,grid,vis,q);
            }
        }
    }
    
    int bfs(vector<vector<int> > &grid,vector<vector<bool> > &vis,queue<pair<int,int> > &q)
    {
        int ans=-1;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            while(size--)
            {
                pair p=q.front(); q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=p.first+dxy[i][0];
                    int y=p.second+dxy[i][1];
                    if(isValid(x,y,vis) && grid[x][y]==1)
                    {
                        return ans;
                    }
                    if(isValid(x,y,vis) && grid[x][y]==0)
                    {
                        vis[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool> > vis(n,vector<bool>(n,false));
        queue<pair<int,int> > q;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,q);
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        return bfs(grid,vis,q);
    }
};