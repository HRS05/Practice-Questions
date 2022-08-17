class Solution {
public:
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) return mat;
        int m=mat[0].size();
        vector<vector<int> > dis(n,vector<int>(m,INT_MAX));      
        int dxy[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int> > q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0) {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=p.first+dxy[i][0]; 
                int y=p.second+dxy[i][1];
                if(x>=0 && x<n && y>=0 && y<m){
                    if(dis[x][y] > dis[p.first][p.second]+1){
                       dis[x][y] = dis[p.first][p.second]+1; 
                        q.push({x,y});
                    }
                }
                
            }
            
        }
        
        return dis;
    }    

//     bool isValid(int i,int j,vector<vector<int> > &mat,vector<vector<bool> > &vis)
//     {
//         int n=mat.size();
//         int m=mat[0].size();
//         if(i<0 || i>=n || j<0 || j>=m || vis[i][j]) return false;
//         return true;
//     }
    
//     int travel(int i,int j,vector<vector<int> > &mat)
//     {
//         int n=mat.size();
//         int m=mat[0].size();
//         queue<pair<int,int> > q;
//         vector<vector<bool> > vis(n,vector<bool>(m,false));
//         int ans=0;
//         q.push({i,j});
//         vis[i][j]=true;
//         while(!q.empty())
//         {
//             int size=q.size();
//             ans++;
//             while(size--){
//                 int x,y;
//                 x=q.front().first;
//                 y=q.front().second;
//                 q.pop();
//                 int value=mat[x][y];
                                
//                 if(isValid(i+1,j,mat,vis)){
//                     vis[i+1][j]=true;
//                     if(mat[i+1][j]==0) return ans;
//                     q.push({i+1,j});
//                 }
//                  if(isValid(i-1,j,mat,vis)){
//                     vis[i-1][j]=true;
//                      if(mat[i-1][j]==0) return ans;
//                      q.push({i-1,j});
//                 }
//                  if(isValid(i,j+1,mat,vis)){
//                     vis[i][j+1]=true;
//                      if(mat[i][j+1]==0) return ans;
//                      q.push({i,j+1});
//                 }
//                  if(isValid(i,j-1,mat,vis)){
//                     vis[i][j-1]=true;
//                      if(mat[i][j-1]==0) return ans;
//                      q.push({i,j-1});
//                 }
//             }
//         }
//         return ans;
//     }
    
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         vector<vector<int> > ans(n,vector<int>(m,0));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(mat[i][j]==1) ans[i][j]=travel(i,j,mat);
//             }
//         }
        
        
//         return ans;
//     }
};