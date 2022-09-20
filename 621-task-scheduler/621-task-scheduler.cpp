class Solution {
public:
    int leastInterval(vector<char>& tasks, int t) {
        
        unordered_map <char,int> mp;
        int mx=0; int mxcnt=0;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
            if(mp[tasks[i]]==mx) mxcnt++;
            else if(mp[tasks[i]]>mx) mx = max(mx, mp[tasks[i]]), mxcnt=1;
        }
        
        int n = (mx-1)*(t+1) + 1;
        n+=mxcnt-1;
        int sz = tasks.size();
        int ans = max(n, sz);
        return ans;
    }
    
    /*
    //importtant solution
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int> > q;
        int time=0;
        int count=0;
        unordered_map<char,int> mp;
        for(char c : tasks)
        {
            mp[c]++;
        }
        for(auto x : mp)
        {
            pq.push({x.second});
        }
        
        while(!pq.empty() || !q.empty())
        {
            time+=1;
            if(!pq.empty())
            {
                if(pq.top()-1 !=0)
                    q.push({pq.top()-1,time+n});
                pq.pop();
            }
            if(!q.empty() && q.front().second == time)
            {
                pq.push({q.front().first});
                q.pop();
            }
        }
        
        // while(!pq.empty())
        // {
        //     auto x = pq.top(); pq.pop();
        //     cout<<x.second<<" "<<x.first<<endl;
        // }
            
        return time;
    }
    */
};