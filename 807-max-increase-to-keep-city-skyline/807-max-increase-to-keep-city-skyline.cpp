class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> row(n),column(n);
        for(int i=0;i<n;i++)
        {
            int rowMax=0;
            int columnMax=0;
            for(int j=0;j<n;j++){
                rowMax=max(rowMax,grid[i][j]);
                columnMax=max(columnMax,grid[j][i]);
            }
            row[i]=rowMax;
            column[i]=columnMax;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++){
                int val=min(row[i],column[j]);
                if(val > grid[i][j]){
                    ans+=val-grid[i][j];
                }
            }
        }
        return ans;
    }
};