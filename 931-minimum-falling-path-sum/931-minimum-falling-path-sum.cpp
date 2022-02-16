class Solution {
public:
    //recursive code
    // TC : O(3^n)
    // SC : stack space O(n)
    int pathSum(vector<vector<int > > &matrix,int i,int j,vector<vector<int> > &dp)
    {
        if(j<0 || j>=matrix.size()) return 100000; //returning 1000 beacuse max constrant is 100
        if(i==0) return dp[i][j]=matrix[i][j];
        
        if(dp[i][j]!=100000) return dp[i][j];
        int i1=matrix[i][j]+pathSum(matrix,i-1,j,dp);            
        int i2=matrix[i][j]+pathSum(matrix,i-1,j-1,dp);
        int i3=matrix[i][j]+pathSum(matrix,i-1,j+1,dp);
            
        return dp[i][j]=min(i1,min(i2,i3));    
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i,j,mini=INT_MAX;
        vector<vector<int> > dp(matrix.size(),(vector<int>(matrix[0].size(),100000)));
            
        for(int j=0;j<matrix[0].size();j++)
        {
            mini=min(mini,pathSum(matrix,matrix.size()-1,j,dp));
        }
        return mini;
    }
};