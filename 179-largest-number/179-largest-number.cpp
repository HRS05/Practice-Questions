class Solution {
public:
    bool static comapre(string s1,string s2)
    {
        string a=s1+s2;
        string b=s2+s1;
        return a>b;
    }
    
    
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int num : nums)
        {
            s.push_back(to_string(num));
        }
        sort(s.begin(),s.end(),comapre);
        string ans="";
        for(string str : s) ans+=str;
        
         if(ans[0]=='0') return "0";
        return ans;
            
    }
};