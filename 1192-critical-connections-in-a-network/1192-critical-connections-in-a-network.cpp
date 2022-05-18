class Solution {
public:
      
    void dfs(int node,int parent,int &timer,vector<int> &tin,vector<int> &low,vector<int> &vis,vector<vector<int> > &adj,vector<vector<int> > &ans)
    {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            if(vis[it]==0)
            {
                dfs(it,node,timer,tin,low,vis,adj,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                {
                    vector<int> v;
                    v.push_back(node);
                    v.push_back(it);
                    ans.push_back(v);
                }
            }
            else
            {
                low[node]=min(low[node],tin[it]);
            }
        }
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector< int > > adj(n);
        vector<vector< int > > ans;
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        int timer=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) 
                dfs(i,-1,timer,tin,low,vis,adj,ans);
        }
        return ans;
    }
};