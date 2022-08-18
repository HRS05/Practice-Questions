class Solution {
public:
    void dfs(int src,vector<vector<int> > &rooms,vector<bool> &vis)
    {
        if(vis[src]) return;
        vis[src]=true;
        for(int nbr : rooms[src])
        {
            if(!vis[nbr]){
                dfs(nbr,rooms,vis);
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        dfs(0,rooms,vis);
        for(bool check : vis){
            //cout<<check<<endl;
            if(!check) return false;
        }
        return true;
    }
};