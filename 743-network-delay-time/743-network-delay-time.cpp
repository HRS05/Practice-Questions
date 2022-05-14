class Solution {
public:
    
    void dfs(int node,vector<vector<pair<int,int> > > &adj,vector<bool> &v,int time,vector<int> &t)
    {
        v[node]=true;
        for(pair<int,int> it:adj[node])
        {
            if(!v[it.first])
            {
                t[it.first]=time+it.second;
                dfs(it.first,adj,v,t[it.first],t);
            }
            else
            {
                if(t[it.first] > time+it.second) 
                {
                    t[it.first]=time+it.second;
                    dfs(it.first,adj,v,t[it.first],t);
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int> > > adj(n+1);
        vector<bool> v(n+1,false);
        vector<int> t(n+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        t[k]=0;
        dfs(k,adj,v,0,t);
        int max=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            cout<<t[i]<<endl;
            if(t[i]>max) max=t[i];
        }
        return max==INT_MAX ? -1 : max; 
    }
};