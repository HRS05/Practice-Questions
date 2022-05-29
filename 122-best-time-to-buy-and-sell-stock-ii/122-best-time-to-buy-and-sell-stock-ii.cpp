class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy;
        buy=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            buy=min(buy,prices[i]);
            if(prices[i] > buy)
            {
                profit+=prices[i]-buy;
                buy=prices[i];
            }
        }
        return profit;
    }
};