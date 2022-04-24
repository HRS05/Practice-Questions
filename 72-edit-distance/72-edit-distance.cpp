class Solution {
public:
    
    
    
    int f(string s1,int n,string s2,int m,vector<vector<int> > &dp)
    {
        if(m==0) return n;
        if(n==0) return m;
        int i1,i2,i3;
        if(dp[n][m]!=-1) return dp[n][m]; 
        i1=i2=i3=INT_MAX;
        if(s1[n-1]==s2[m-1]) return dp[n][m]=f(s1,n-1,s2,m-1,dp);
        i1=1+f(s1,n-1,s2,m-1,dp);
        i2=1+f(s1,n-1,s2,m,dp);
        i3=1+f(s1,n,s2,m-1,dp);
        return dp[n][m]=min({i1,i2,i3});
    }
    
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
        if(n==0 && m==0) return 0;
        return f(word1,n,word2,m,dp);
    }
};