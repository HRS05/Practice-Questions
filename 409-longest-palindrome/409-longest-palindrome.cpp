class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        bool once=false;
        for(auto x : mp)
        {
            
            count+=x.second-(x.second%2);
            if(once==false)
            {
                if(x.second % 2 !=0) { once=true; count++; }
            }
        }
        return count;
    }
};