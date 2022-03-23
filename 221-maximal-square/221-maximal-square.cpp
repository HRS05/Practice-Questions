class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        vector<vector<int> > dp(rows+1,vector<int>(columns+1,0));
        int maxSquareLength=0;
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=columns;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]) , dp[i-1][j-1])+1;
                    maxSquareLength=max(maxSquareLength,dp[i][j]);
                }
            }
        }
        return maxSquareLength * maxSquareLength;
    }
};