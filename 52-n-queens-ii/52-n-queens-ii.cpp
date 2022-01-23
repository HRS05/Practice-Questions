class Solution {
public:
    
    void solve(int column,int *count,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal)
    {
        int n=leftRow.size();
        if(column==n)
        {
            *count=*count+1;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && upperDiagonal[row+column]==0 && lowerDiagonal[n-1+column-row]==0)
            {
                leftRow[row]=1;
                upperDiagonal[row+column]=1;
                lowerDiagonal[n-1+column-row]=1;
                solve(column+1,count,leftRow,upperDiagonal,lowerDiagonal);
                leftRow[row]=0;
                upperDiagonal[row+column]=0;
                lowerDiagonal[n-1+column-row]=0;
            }
        }
    }
    
    
    int totalNQueens(int n) {
        int count=0;
        vector<int> leftRow(n,0),upperDiagonal(2 * n-1,0),lowerDiagonal(2 * n-1,0);
        solve(0,&count,leftRow,upperDiagonal,lowerDiagonal);
        return count;
    }
};