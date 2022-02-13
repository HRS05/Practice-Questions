class Solution {
public:
    
    void solve(vector<vector<int> > &ans,vector<int> &v,int n,int k,int index)
    {
        if(k==v.size()){
            ans.push_back(v);
            return;
        }
        if(index==n+1) return;
                
                v.push_back(index);
                solve(ans,v,n,k,index+1);
                v.pop_back();
                solve(ans,v,n,k,index+1);
    }
    
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > ans;
        vector<int> v;
        solve(ans,v,n,k,1);
        
        return ans;
    }
};