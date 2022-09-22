class Solution {
public:
    void broLetsGo(int i,int f,string &s)
    {
        while(i<f)
        {
            swap(s[i],s[f]);
            i++;f--;
        }
    }
    
    
    string reverseWords(string s) {
        int x;
        x=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                broLetsGo(x,i-1,s);
                x=i+1;
            }
        }
        broLetsGo(x,s.size()-1,s);
        return s;
    }
};