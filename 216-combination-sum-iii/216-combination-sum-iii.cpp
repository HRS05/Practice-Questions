class Solution {
public:
    
    void solve(int k,int n,vector<vector<int> > &ans,vector<int> &v,int num)
    {
        if(v.size()>k || n<0) return ;
        if(v.size()==k && n==0)
        {
            ans.push_back(v);
            return;
        }
        if(num>9) return;
        v.push_back(num);
        solve(k,n-num,ans,v,num+1);
        v.pop_back();
        solve(k,n,ans,v,num+1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> v;
        solve(k,n,ans,v,1);
        return ans;
    }
};