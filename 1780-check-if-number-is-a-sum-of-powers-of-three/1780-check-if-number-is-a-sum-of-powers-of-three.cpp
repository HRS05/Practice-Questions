class Solution {
public:
    
    bool check(int n,int p)
    {
        if(n==0) return true;
        if(p>n) return false;
        return check(n-p,p*3) || check(n,p*3);
    }
    
    bool checkPowersOfThree(int n) {
        return check(n,1);
    }
};