class Solution {
public:
    
    void getNumbers(int n,int k,vector<int> &ans,int lastNum,int num)
    {
        if(n==0)
        {
            ans.push_back(num);
            return;
        }
        if(lastNum+k <= 9)
        {
            int n1=num*10;
            n1+=lastNum+k;
            getNumbers(n-1,k,ans,lastNum+k,n1);
        }
        if(lastNum-k >= 0 && lastNum-k!=lastNum+k)
        {
            int n2=num*10;
            n2+=lastNum-k;
            getNumbers(n-1,k,ans,lastNum-k,n2);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<=9;i++) getNumbers(n-1,k,ans,i,i);
        return ans;
    }
};