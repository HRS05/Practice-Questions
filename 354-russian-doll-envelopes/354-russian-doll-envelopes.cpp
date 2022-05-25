class Solution {
public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
        
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp;
        for (auto& env : envelopes) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
    
    /*
    //recursive  (memoized code)
    int f(int index,int w,int h,vector<vector<int> > &envelopes,vector<vector<vector<int> > > &dp){
        if(index >= envelopes.size()) return 0;
        if(dp[index][w][h]!=-1) return dp[index][w][h];
        if(w < envelopes[index][0] && h < envelopes[index][1])
        {
            return dp[index][w][h]=max((1+f(index+1,envelopes[index][0],envelopes[index][1],envelopes,dp)),f(index+1,w,h,envelopes,dp));
        }
        return dp[index][w][h]=f(index+1,w,h,envelopes,dp);
    }
    
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(envelopes[n-1][0]+1,vector<int>(1000+1,-1))); 
        return f(0,0,0,envelopes,dp); 
    }
    */
};