class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    maxArea=max(maxArea,findArea(grid,i,j));
                }
            }
        }
        
        return maxArea;
        
    }
    
    int findArea(vector<vector<int> >& grid,int sr,int sc)
         {
             if(sr<0 || sc<0 || sr>=grid.size() || sc>=grid[0].size()) return 0;
             if(grid[sr][sc]==1)
             {
              grid[sr][sc]=0;   
             return 1+findArea(grid,sr+1,sc) + findArea(grid,sr-1,sc) + findArea(grid,sr,sc+1) + findArea(grid,sr,sc-1);
             }
             return 0;
         }
};