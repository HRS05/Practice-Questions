class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        priority_queue<pair<int,int> >  pq;
        for(int num : nums)
        {
            mp[num]++;
        }
        for(auto ele : mp)
        {
            pq.push({ele.second,ele.first});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};