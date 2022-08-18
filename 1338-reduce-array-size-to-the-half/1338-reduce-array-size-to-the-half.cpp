class Solution {
public:
    int minSetSize(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        priority_queue<pair<int,int> > q;
        int prev=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt++;
            if(i+1<n && arr[i+1]!=arr[i]) {
                q.push({cnt,arr[i]});
                cnt=0;
            }else if(i+1==n) {
                q.push({cnt,arr[i]});
            }
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
    
    
    /*
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
    }*/
};