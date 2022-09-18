class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count=1;
        int maxCount=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]+1 == s[i]) count++;
            else {
                if(maxCount < count)
                {
                    maxCount=count;
                }
                count=1;
            }
        }
        if(maxCount < count)
                {
                    maxCount=count;
                }
        return maxCount;
    }
};