class Solution {
public:
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
};