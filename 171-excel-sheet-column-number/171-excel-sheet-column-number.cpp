class Solution {
public:
    int titleToNumber(string columnTitle) {
        int num=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            int x=columnTitle[i]-64;
            num= (num*26)+x;
        }
        return num;
    }
};