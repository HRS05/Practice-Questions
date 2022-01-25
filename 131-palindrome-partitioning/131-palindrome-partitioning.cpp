class Solution {
public:
    
    void solve(vector<vector<string>> &ans,vector<string> &path,string s,int index)
    {
        if(index==s.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                solve(ans,path,s,i+1);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int start,int end)
    {
        if(start<=end)
        {
            if(s[end]!=s[start]) return false;
            return isPalindrome(s,++start,--end);
        }
        else return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> path;
        solve(ans,path,s,0);
        return ans;
    }
};