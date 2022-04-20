class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        
        for(int i=0;i<k;i++)
        {
            int x=pq.top()+1; pq.pop();
            pq.push(x);
        }
        
        long long int ans=1;
        long long int mod=1e9+7;
        while(!pq.empty())
        {
            ans=((ans%mod)*(pq.top()%mod))%mod;
            pq.pop();
        }
        return (int)ans%mod;
    }
};