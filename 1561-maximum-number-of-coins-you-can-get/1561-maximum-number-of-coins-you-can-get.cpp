class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        n=n/3;
        if(n==0) return 0;
        sort(piles.begin(),piles.end());
        int x=piles.size()-2;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=piles[x];
            x=x-2;
        }
        return ans;
    }
};