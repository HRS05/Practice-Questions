class Solution {
public:
    void travel(int src,vector<vector<int> > &isConnected,vector<bool> &vis)
    {
        if(vis[src]) return;
        vis[src]=true;
        for(int nbr=0;nbr<isConnected[0].size();nbr++)
        {
            if(nbr!=src && isConnected[src][nbr]==1 && !vis[nbr])
            {
                travel(nbr,isConnected,vis);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                travel(i,isConnected,vis);
                count++;
            }
        }
        
            
        return count;
    }
};