class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int pp=1;
        int nn=1;
        int num;
        for(int i=3;i<=n;i++)
        {
            num=pp+nn;
            pp=nn;
            nn=num;
        }
        return num;
    }
};