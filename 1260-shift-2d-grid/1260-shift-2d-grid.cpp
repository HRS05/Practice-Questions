class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
         int row=grid.size();
        int col=grid[0].size();
       
        if(k==row*col || k==0){
            return grid;
        }
        
        
        int last;
        int temp;
        while(k--){
            last = grid[row-1][col-1];
            for(int i=0;i<row;i++){
                temp=grid[i][col-1];
                for(int j=col-1;j>0;j--){
                    grid[i][j]=grid[i][j-1];
                }
                grid[i][0]=last;
                last=temp;
            }
            
        }
        
        return grid;
    }
};