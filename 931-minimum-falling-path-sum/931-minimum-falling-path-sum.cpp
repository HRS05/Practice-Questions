class Solution {
public:
    
    //tabulation code
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i,j;
        vector<vector<int> > dp(matrix.size(),(vector<int>(matrix[0].size(),0)));
            
        for(int k=0;k<matrix[0].size();k++)
        {
            dp[0][k]=matrix[0][k];
        }
        
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int i1,i2,i3;
                i1=i2=i3=100000;
                i1=matrix[i][j]+dp[i-1][j];
                if(j > 0) i2=matrix[i][j]+dp[i-1][j-1];
                if(j < matrix[0].size()-1) i3=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(i1,min(i2,i3));
            }
        }
        
        return *min_element(dp[matrix.size()-1].begin(),dp[matrix.size()-1].end());
    }
    
    
    /*
    //memoized code
    //TC : O(m*N) 
    //SC : O(m*n)+O(n)
    int pathSum(vector<vector<int > > &matrix,int i,int j,vector<vector<int> > &dp)
    {
        if(j<0 || j>=matrix.size()) return 100000; //returning 100000 beacuse max constrant is 100
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
    */
    
    /*
    //recursive code
    // TC : O(3^n)
    // SC : stack space O(n)
    int pathSum(vector<vector<int > > &matrix,int i,int j)
    {
        if(i<0 || j<0 || j>=matrix.size()) return 100000;
        if(i==0) return matrix[i][j];
        
        int i1=matrix[i][j]+pathSum(matrix,i-1,j);            
        int i2=matrix[i][j]+pathSum(matrix,i-1,j-1);
        int i3=matrix[i][j]+pathSum(matrix,i-1,j+1);
            
        return min(i1,min(i2,i3));    
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int i,j,mini=INT_MAX;
        for(int j=0;j<matrix[0].size();j++)
        {
            mini=min(mini,pathSum(matrix,matrix.size()-1,j));
        }
        return mini;
    }
    */
    
};