class Solution {
public:
    
    
    int nthUglyNumber(int n) {
        int x2,x3,x5;
        x2=x3=x5=0;
        vector<int> dp(n+1,1);
        for(int i=1;i<=n;i++)
        {
            dp[i]=min({2*dp[x2],3*dp[x3],5*dp[x5]});
            if(dp[i] == dp[x2]*2){
                x2++;
            }
            if(dp[i] == dp[x3]*3){
                x3++;
            }
            if(dp[i] == dp[x5]*5){
                x5++;
            }
        }
        return dp[n-1];
    }
    
    /*
    //TLE
    int nthUglyNumber(int nn) {
        int i=1;
        int count=0;
        while(1)
        {
            int n=i;
            while(n>1)
            {
                if(n%5==0) n/=5;
                else if(n%3 == 0) n/=3;
                else if(!(n & 1)) n>>=1; 
                else {
                    count--;
                    break;
                }
            }
            count++;
            if(count==nn) break;
            i++;
        }
        return i;
    }
    */
};