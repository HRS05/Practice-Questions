class Solution {
public:
    
    bool check(vector<vector<int> > &grid,int r,int c,int &count)
    {
        int n=grid.size();
        int m=grid[0].size();
        if((r<1 || r>=n-1 || c<1 || c>=m-1) && grid[r][c]==1) return false;
        if((r<1 || r>=n-1 || c<1 || c>=m-1) && grid[r][c]==0) return true;
        if(grid[r][c]==2 || grid[r][c]==0) return true;
        if(grid[r][c]==3) return false;
        grid[r][c]=2;
        count++;
        bool ans=true;
        ans = ans && check(grid,r+1,c,count);
        ans = ans && check(grid,r,c+1,count);
        ans = ans && check(grid,r-1,c,count);
        ans = ans && check(grid,r,c-1,count);
        if(!ans) grid[r][c]=3;
        return ans;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans{0};
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int count{0};
                if(grid[i][j]==1 && check(grid,i,j,count)){
                    cout<<i<<"  "<<j<<endl;
                    ans+=count;
                }
            }
        }
        return ans;
    }
};