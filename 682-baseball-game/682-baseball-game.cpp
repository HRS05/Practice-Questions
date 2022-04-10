
class Solution {
public:
    int number(string s)
    {
        int ans=0;
        int x,i=0;
        if(s[0]=='-') {
            x=-1;
            i++;
        }
        else x=1;
            
        for(;i<s.size();i++)
        {
            ans*=10;
            ans+=s[i]-48;
        }
        return ans*x;
        
    }
    
    int calPoints(vector<string>& ops) {
        vector<int> v;
        int n;
        for(string s : ops)
        {
            n=v.size();
            if(s=="D")
            {
                v.push_back(v[n-1] * 2);
            }
            else if(s=="C")
            {
                v.pop_back();
            }
            else if(s=="+")
            {
                v.push_back(v[n-1]+v[n-2]);
            }
            else
            {
                v.push_back(number(s));
            }
        }
        int ans=0;
        for(int num : v) ans+=num;
        return ans;
    }
};