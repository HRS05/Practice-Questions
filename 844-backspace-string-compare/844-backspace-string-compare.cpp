class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i=0;i<s.size();i++)
        {
            if(i>0 && s[i]=='#') {
                int j=i;
                while(j>0 && s[j]=='#') j--;
                if(j>=0) s[j]='#';
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(i>0 && t[i]=='#') {
                int j=i;
                while(j>0 && t[j]=='#') j--;
                if(j>=0) t[j]='#';
            }
        }
        cout<<"s : "<<s<<"  t : "<<t<<endl;
        int i,j;
        i=j=0;
        while(i<s.size() && j<t.size())
        {
            while(s[i]=='#') i++;
            while(t[j]=='#') j++;
            if(i==s.size() && j==t.size()) return true;
            cout<<"i : "<<i<<"  j : "<<j<<endl;
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else return false;
            while(s[i]=='#') i++;
            while(t[j]=='#') j++;
        }
        if(i==s.size() && j==t.size()) return true;
        return false;
    }
};