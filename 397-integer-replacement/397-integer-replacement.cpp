class Solution {
public:
    int integerReplacement(int n) {
        if(n==1) return 0;
        if(n%2==0) return 1+integerReplacement(n/2);
        return 1+min(n==INT_MAX ? INT_MAX : integerReplacement(n+1),n==INT_MAX ? integerReplacement(n-1)-1 : integerReplacement(n-1));
        
    }
};