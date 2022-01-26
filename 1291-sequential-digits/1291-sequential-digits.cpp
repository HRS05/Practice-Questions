class Solution {
public:
    
    void solve(vector<int> &ans,int low,int high,int num,int index)
    {
        if(num>=low && num<=high)
        {
            ans.push_back(num);
        }
        if(num>high) return;
        
        num*=10;
        if(index<=9)solve(ans,low,high,num+index,index+1);
    }
    
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=8;i++) solve(ans,low,high,i,i+1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};