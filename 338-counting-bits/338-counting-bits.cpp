class Solution {
public:
    vector<int> countBits(int n) {
        int count;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            count=0;
            int x=i;
            while(x)
            {
                count+=(x & 1);
                x>>=1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};