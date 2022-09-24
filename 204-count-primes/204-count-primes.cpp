class Solution {
public:
    int countPrimes(int n) {
        //Make a vector of bool and assign all no from 0-n as prime.
        //Exclude 1,start with 2 and if its prime make all its multiples as false- not prime.
        if(n==0 || n==1) return 0;
        vector<int> check(n,true);
        check[0]=check[1]=false;
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(check[i])
            {
                count++;
                int k=2;
                for(int x=2*i;x<n;x=i*k)
                {
                    check[x]=false;
                    k++;
                }
            }
            
        }
        return count;
    }
};