class Solution {
public:
    
    bool checkForSubIsland(vector<vector<int> > &grid1,vector<vector<int> > &grid2,int r,int c)
    {
        int n=grid1.size();
        int m=grid1[0].size();
        bool ans=true;
        if(r<0 || r>=n || c<0 || c>=m) return true;
        
        if(grid1[r][c]==grid2[r][c] && grid1[r][c]==2 ) return true;
        if(grid1[r][c]==grid2[r][c] && grid1[r][c]==0 ) return true;
        if(grid1[r][c]==0 && grid2[r][c]==1) return false;
        if(grid1[r][c]==1 && grid2[r][c]==0) return true;
        
        
        grid1[r][c]=2;
        grid2[r][c]=2;
        ans=ans && checkForSubIsland(grid1,grid2,r+1,c);
        ans=ans &&  checkForSubIsland(grid1,grid2,r-1,c);
        ans=ans &&  checkForSubIsland(grid1,grid2,r,c+1);
        ans=ans && checkForSubIsland(grid1,grid2,r,c-1);  
        if(!ans) grid2[r][c]=1;
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans{0};
        int n=grid1.size();
        int m=grid1[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && grid1[i][j]==1)
                {
                    if(checkForSubIsland(grid1,grid2,i,j)){
                        //cout<<i<<"  "<<j<<endl;
                        ans++;
                    }
                }
            }
        }
        return ans;    
    }
};