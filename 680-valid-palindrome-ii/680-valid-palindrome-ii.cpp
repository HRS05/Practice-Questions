class Solution {
public:
    
    bool check(string s,int i,int f)
    {
        while(i<f)
        {
            if(s[i]!=s[f]) return false;
            i++;
            f--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i=0;
        int f=s.size()-1;
        
        while(i<f)
        {
            if(s[i]!=s[f])
            {
               return check(s,i+1,f)|| check(s,i,f-1);
            }
            i++; f--;
        }
        return true;
    }
};