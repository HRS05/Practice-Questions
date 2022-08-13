class Solution {
private:
    
    void walkAround(vector<vector<int> > &adj,int src,vector<bool> &vis,int &value)
    {
        if(src >= adj.size() || vis[src]) return;
        vis[src]=true;
        value++;
        for(int nbr : adj[src])
        {
            if(!vis[nbr]){
                walkAround(adj,nbr,vis,value);
            }
        }
                
    }

public:
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adj(n);
        vector<long long> nodeCount;
        vector<bool> vis(n,false);
            
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long count=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int value=0;
            if(!vis[i]){
               walkAround(adj,i,vis,value);
               nodeCount.push_back(value);
            }
        }
        for(long long num : nodeCount){
            count=num * (n-num);
            ans+=count;
        }
        return ans/2;
    }
};