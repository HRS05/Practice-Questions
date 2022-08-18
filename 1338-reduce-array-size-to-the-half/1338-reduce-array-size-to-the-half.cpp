class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        for(int num : arr)
        {
            mp[num]++;
        }
        priority_queue<pair<int,int> > q;
        for(pair<int,int> p : mp)
        {
            q.push({p.second,p.first});
        }
        int count=arr.size();
        int ans=0;
        while(!q.empty() && count>arr.size()/2)
        {
            pair<int,int> p=q.top();
            q.pop();
            ans++;
            count-=p.first;
            //cout<<p.first<<"  "<<p.second<<endl;
        }
        return ans;
    }
};