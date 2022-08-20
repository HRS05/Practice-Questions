class Solution {
public:
    
    bool dfs(int src,vector<int> &color,vector<vector<int> > &graph)
    {
        if(color[src]>0) return color[src]==2 ? true : false;
        color[src]=1;
        for(int nbr : graph[src])
        {
            //if(color[src]==2) continue;
            if(color[nbr]==1 || !dfs(nbr,color,graph)) return false;
            
        }
        color[src]=2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
        
            if(dfs(i,color,graph))
                ans.push_back(i);
        }
        
        return ans;
    }
};