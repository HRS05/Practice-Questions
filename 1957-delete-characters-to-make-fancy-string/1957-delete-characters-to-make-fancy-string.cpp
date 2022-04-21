class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        char c=' ';
        int count;
        for(char ch : s)
        {
            if(c!=ch){
                count=1;
                c=ch;
            }
            if(c==ch) count++;
            if(count<=3){
                ans+=ch;
            }
        }
        return ans;
    }
};