class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int> > dp(6,vector<int>(n+1,0));
        for(int i=0;i<6;i++) dp[i][0]=1;
        
        for(int i=1;i<6;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int l1=dp[i][j-1];
                int l2=dp[i-1][j];
                dp[i][j]=l1+l2;
            }
        }
        
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[5][n];
    }
};