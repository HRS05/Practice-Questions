class Solution {
public:
    
    int numberOfSteps(int num) 
    {
        if(num==0) return 0;
        int count=0;
        while(num>0)
        {
            count += 1 + (num & 1);
            num>>=1;
        }
        return count-1;
    }
    
    // int numberOfSteps(int num) {
    //     int ans=0;
    //     while(num>0)
    //     {
    //         if(num%2==0) num/=2;
    //         else num--;
    //         ans++;
    //     }
    //     return ans;
    // }
};