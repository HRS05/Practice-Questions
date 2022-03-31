class Solution {
public:
    //TC : O(n)
    vector<int> countBits(int n) {
    vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i & (i-1)]+1;
        }
        return dp;    
    }
            
    
    /*
    //TC : O(nlongn)
    vector<int> countBits(int n) {
        int count;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            count=0;
            int x=i;
            while(x)
            {
                count+=(x & 1);
                x>>=1;
            }
            ans.push_back(count);
        }
        return ans;
    }
    */
};