class Solution {
public: 
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mode=1e9+7;
        long long ans=0;
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++) v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        
        long long topKSum=0;
        for(int i=0;i<n;i++)
        {
            int currMinEff = v[i].first;
            
            long long maxVal=v[i].second + topKSum;
            
            ans=max(ans , maxVal*currMinEff);
            
            pq.push(v[i].second);
            
            topKSum += v[i].second;
            
            if(pq.size()>k-1) 
            {
                topKSum -=pq.top();
                pq.pop();
            }
            
        }
        return ans%mode;
    }
};