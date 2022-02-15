class Solution {
public:
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int > > dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[n-1][i]=triangle[n-1][i];    
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<i+1;j++)
            {
                int i1=dp[i+1][j]+triangle[i][j];
                int i2=dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(i1,i2);
            }
        }
        
        return dp[0][0];
    }
    
    /*
    //memoized code
    int count(vector<vector<int> > &triangle,int i,int j,vector<vector<int> > &dp)
    {
        if(i==triangle.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int i1=triangle[i][j]+count(triangle,i+1,j,dp);
        int i2=triangle[i][j]+count(triangle,i+1,j+1,dp);
        return dp[i][j]=min(i1,i2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int > > dp(n,vector<int>(n,-1));
        return count(triangle,0,0,dp);
    }
    */
    
    /*
    //recursive code
     int count(vector<vector<int> > &triangle,int i,int j)
    {
        if(i==triangle.size())
        {
            return 0;
        }
        
        int i1=triangle[i][j]+count(triangle,i+1,j);
        int i2=triangle[i][j]+count(triangle,i+1,j+1);
        return min(i1,i2);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        return count(triangle,0,0);
    }
    */
};