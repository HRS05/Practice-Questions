class Solution {
public:
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int ss,ee,dd;
        int n=shifts.size();
        int m=s.size();
        vector<int> v(m+1,0);
        
        for(int i=0;i<n;i++)
        {
            ss=shifts[i][0];
            ee=shifts[i][1];
            dd=shifts[i][2]==1 ? 1 : -1;
            v[ss]+=dd;
            v[ee+1]-=dd;
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=v[i];
            int x=s[i]+(sum%26);
            if(x<'a') x+=26;
            if(x>'z') x-=26;
            s[i]=x;
            
        }
        
        return s;
    }
    
    
    /*
    //TLE solu
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int ss,ee,dd;
        int n=shifts.size();
        
        for(int i=0;i<n;i++)
        {
            ss=shifts[i][0];
            ee=shifts[i][1];
            dd=shifts[i][2];
            if(dd)
            {
                for(int j=ss;j<=ee;j++)
                {
                    if(s[j]=='z') s[j]='a';
                    else s[j]++;
                }
            }
            else
            {
                for(int j=ss;j<=ee;j++)
                {
                    if(s[j]=='a') s[j]='z';
                    else s[j]--;
                }
            }
        }
        
        return s;
    }*/
};