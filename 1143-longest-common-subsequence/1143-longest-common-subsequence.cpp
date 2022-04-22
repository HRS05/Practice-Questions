class Solution {
public:
    
    //tabulation solution
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int i1,i2;
                i1=i2=0;
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return dp[n][m];
    }
    
    
    /*
    //recursive and memoized solution
    //TC : O(n*m)
    //SC : O(n*m) + O(n+m)
    int f(string text1,int index1,string text2,int index2,vector<vector<int> > &dp)
    {
        if(index1==0 || index2==0) return 0;
        int i1,i2,i3; 
        i1=i2=0;
        if(dp[index1][index2]!=-1) return dp[index1][index2]; 
        if(text1[index1]==text2[index2]) 
            return dp[index1][index2]=f(text1,index1-1,text2,index2-1,dp)+1;
        i1=f(text1,index1-1,text2,index2,dp);
        i2=f(text1,index1,text2,index2-1,dp);
        return dp[index1][index2]=max(i1,i2);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
        return f(text1,n,text2,m,dp);
    }
    */
};