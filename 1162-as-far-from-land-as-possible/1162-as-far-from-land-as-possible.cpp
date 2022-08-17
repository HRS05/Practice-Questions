class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int maxDistance(vector<vector<int>>& grid) {
        int ans=-1;
        int n=grid.size();
        vector<vector<int>> ansData(n,vector<int>(n,-1));  
        bfs(grid,ansData);
        for(vector<int> x : ansData)
        {
            for(int y : x)
            {
                ans=max(ans,y);
            }
        }
        return ans==0 ? -1 : ans;
    }
    
    void bfs(vector<vector<int> > &grid,vector<vector<int> > &ansData)
    {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    ansData[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(isValid(x+dx[i],y+dy[i],grid)){
                    q.push({x+dx[i],y+dy[i]});
                    ansData[x+dx[i]][y+dy[i]]=ansData[x][y]+1;
                    grid[x+dx[i]][y+dy[i]]=1;
                }
            }
        }
    }
    
    bool isValid(int i,int j,vector<vector<int> > &grid)
    {
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==1) return false;
        return true;
    }
    
};