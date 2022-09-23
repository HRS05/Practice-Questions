class Solution {
public:
    int numberOfBits(int n) 
    {
        //counting numbers of leading 0's in number
        int leadingZeros = __builtin_clz(n);
        //returning the length of number
        return 32 - leadingZeros;
    }

    int concatenatedBinary(int n) 
    {
        long ans = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; ++i) 
        {
            int len = numberOfBits(i);
            //ans<<len is use for shifting the bit in left for length of i times
            //then we add the i number 
            // with this we are also taking mode of it for restricting the limit of number to cross it size of 32 bits
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};