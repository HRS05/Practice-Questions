class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n > 0)
        {
            n=n & (n-1);
            ans++;
        }
        return ans;
    }
    /*
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n > 0)
        {
            //n=n & (n-1);
            int x=(n&1);
            if(x)ans++;
            n>>=1;
        }
        return ans;
    }
    */
};