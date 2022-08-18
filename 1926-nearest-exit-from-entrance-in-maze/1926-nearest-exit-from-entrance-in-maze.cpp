class Solution {
public:
     bool isValid(int i, int j, int n, int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    bool isBoundary(int i, int j, int n, int m){
        return (i==0 || j==0 || i==n-1 || j==m-1);
    }
    bool isEntrance(int i, int j, int n, int m){
        return (i==n && j==m);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto f=q.front();
            q.pop();
            int x=f.first;
            int y=f.second;
            // cout<<x<<" "<<y<<endl;
            if(isValid(x+1,y,n,m) && maze[x+1][y]=='.' && vis[x+1][y]==INT_MAX){
                if(isBoundary(x+1,y,n,m) && !isEntrance(x+1,y,entrance[0],entrance[1])){
                    return vis[x][y];
                }
                vis[x+1][y]=vis[x][y]+1;
                q.push({x+1,y});
            }
            if(isValid(x,y+1,n,m) && maze[x][y+1]=='.' && vis[x][y+1]==INT_MAX){
                if(isBoundary(x,y+1,n,m) && !isEntrance(x,y+1,entrance[0],entrance[1])){
                    return vis[x][y];
                }
                vis[x][y+1]=vis[x][y]+1;
                q.push({x,y+1});
            }
            if(isValid(x-1,y,n,m) && maze[x-1][y]=='.' && vis[x-1][y]==INT_MAX){
                if(isBoundary(x-1,y,n,m) && !isEntrance(x-1,y,entrance[0],entrance[1])){
                    return vis[x][y];
                }
                vis[x-1][y]=vis[x][y]+1;
                q.push({x-1,y});
            }
            if(isValid(x,y-1,n,m) && maze[x][y-1]=='.' && vis[x][y-1]==INT_MAX){
                if(isBoundary(x,y-1,n,m) && !isEntrance(x,y-1,entrance[0],entrance[1])){
                    return vis[x][y];
                }
                vis[x][y-1]=vis[x][y]+1;
                q.push({x,y-1});
            }
        }
        return -1;
    } 
    
    
    
    /*
    //my Solution showing TLE
    int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isBorder(int i,int j,int n,int m)
    {
        if(i==0 || i==n-1 || j==0 || j==m-1) return true;
        return false;
    }
    
    bool isValid(int i,int j,int n,int m,vector<vector<char> > &maze)
    {
        if(i<0 || i>=n || j<0 || j>=m || maze[i][j]=='+' || maze[i][j]==2) return false; 
        return true;
    }
    
    int nearestExit(vector<vector<char>>& maze, v ector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int> > q;
        int ans=0;
        int i=entrance[0];
        int j=entrance[1];
        q.push({i,j});
        maze[i][j]=2;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            while(size--)
            {
                pair<int,int> p=q.front(); q.pop();
                i=p.first;
                j=p.second;
                //if(!(p.first==i && p.second==j) && isBorder(p.first,p.second,n,m)) return ans-1;
                maze[p.first][p.second]=2;
                for(int k=0;k<4;k++)
                {
                    int x=i+dxy[k][0];
                    int y=j+dxy[k][1];
                    if(isValid(x,y,n,m,maze)){
                        if(isBorder(x,y,n,m)) return ans;
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    } */
};