class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int> > grid(n,vector<int>(n,n));
        for(int i=0;i<mines.size();i++)
        {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            int j,k;
            j=0;
            k=n-1;
            int l=0,r=0,u=0,d=0;
            for(;j<n;j++,k--)
            {
                grid[i][j]=min(grid[i][j] , l = ((grid[i][j]==0) ? 0 : l+1));
                grid[i][k]=min(grid[i][k] , r = ((grid[i][k]==0) ? 0 : r+1));
                grid[j][i]=min(grid[j][i] , u = ((grid[j][i]==0) ? 0 : u+1));
                grid[k][i]=min(grid[k][i] , d = ((grid[k][i]==0) ? 0 : d+1));
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                count=max(count,grid[i][j]);
            }
        }
        return count;
    }
    
    
    /*
    //TLE Solution (N^3)
    int f(int i,int j,vector<vector<int> > &mines,int n)
    {
        int count=1;
        int x1,x2,y1,y2;
        x1=i+1;
        x2=i-1;
        y1=j+1;
        y2=j-1;
        while(1)
        {
            if(x1>=n || mines[x1][j]!=1) break;
            x1++;
            if(x2<0 || mines[x2][j]!=1) break;
            x2--;
            if(y1>=n || mines[i][y1]!=1) break;
            y1++;
            if(y2<0 || mines[i][y2]!=1) break;
            y2--;
            count++;
        }
        return count;
    }
    
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int count=0;
        vector<vector<int> > grid(n,vector<int>(n,1));
        
        for(int i=0;i<mines.size();i++)
        {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    count=max(count,f(i,j,grid,n));
                }
            }
        }
        return count;
    }
    */
    
    
    
    
};