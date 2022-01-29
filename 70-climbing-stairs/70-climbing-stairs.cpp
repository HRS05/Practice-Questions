class Solution {
public:
    
    int climbStairs(int n) {
        //fibonacci by observation
        int x,y,num;
        x=0;
        y=1;
        for(int i=1;i<=n;i++)
        {
            num=x+y;
            x=y;
            y=num;
        }
        return num;
        /*
        //dp approach
        int dp[45]={-1};
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
        */
    }
};