class Solution {
public:
    
    
    int countOrders(int n) {
        
        long long mode=1e9+7;
        long long ans=1;
        
        for(int i=2;i<=n;i++)
        {
            int spaceCount=(i-1)*2+1;
            ans*=spaceCount*(spaceCount+1)/2;
            ans=ans%(mode);
        }
        return (int)ans;
    }
};

/*
//explanation
https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/516951/C%2B%2BJavaPython-Simple-Math-Formula-with-Explanation-Clean-and-Concise
*/