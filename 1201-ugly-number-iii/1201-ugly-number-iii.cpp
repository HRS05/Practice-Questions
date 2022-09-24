class Solution {
public:
    //confusion
    int nthUglyNumber(int n, int A, int B, int C) {
        int low=1, high = 2e9;
        long a=long(A), b=long(B), c=long(C);
        long ab=a*b/__gcd(a,b);
        long bc=b*c/__gcd(b,c);
        long ac=a*c/__gcd(a,c);
        long abc=a*bc/__gcd(a,bc);
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int cnt=mid/a+mid/b+mid/c-mid/ab-mid/bc-mid/ac+mid/abc;
            if(cnt<n)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};