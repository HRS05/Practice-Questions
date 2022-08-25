class Solution {
public:
    int helper(int i,int prev,vector<vector<int> > &pairs,vector<vector<int> > &dp)
    {
        if(i>=pairs.size()) return 0;
        if(dp[i][prev+1001]!=-1) return dp[i][prev+1001];
        int x=0;
        if(prev < pairs[i][0]) x=1+helper(i+1,pairs[i][1],pairs,dp);
        int y=helper(i+1,prev,pairs,dp);
        return dp[i][prev+1001]=max(x,y);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        int prev=-1001;
        vector<vector<int> > dp(n,vector<int>(2002,-1));
        return helper(0,prev,pairs,dp);
    }
};