class Solution {
public:
    int f(int n,int headID,map<int,vector<int> > &adj,vector<int> &informTime,vector<bool> &vis)
    {
        int ans=0;
        vis[headID]=true;
        for(auto nbr : adj[headID])
        {
            if(!vis[nbr])
            {
                ans=max(ans,f(n,nbr,adj,informTime,vis));
            }
        }
        return ans+informTime[headID];
    }
        
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        map<int,vector<int> > adj;
        vector<bool> vis(n,false);
        for(int i=0;i<manager.size();i++)
        {
            adj[manager[i]].push_back(i);
        }
        return f(n,headID,adj,informTime,vis);
        
    }
};