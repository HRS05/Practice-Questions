class Solution {
public:
    
    void solve(vector<string> &ans,int n,int closeCount,int openCount,string s)
    {
        if(s.size()==2*n)
        {
            ans.push_back(s);
            return;
        }
        if(openCount==0 && closeCount==0)
        {
            solve(ans,n,closeCount,openCount+1,s+"(");    
        }
        else
        {
        if(openCount<n) solve(ans,n,closeCount,openCount+1,s+"(");    
        if(closeCount<n && closeCount<openCount) solve(ans,n,closeCount+1,openCount,s+")");    
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        int openCount=0;
        int closeCount=0;
        string s="";
        vector<string> ans;
        solve(ans,n,closeCount,openCount,s);
        return ans;
    }
};