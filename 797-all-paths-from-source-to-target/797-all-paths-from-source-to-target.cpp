class Solution {
public:
    
    void travel(int src,vector<vector<int> > &graph,vector<vector<int> > &ans,int lastVisit,vector<int> &traveller)
    {
        if(src==graph.size()-1){
            traveller.push_back(src);
            ans.push_back(traveller);
            traveller.pop_back();
            return;
        }
        traveller.push_back(src);
        for(int nbr : graph[src])
        {
            if(nbr!=lastVisit){
                travel(nbr,graph,ans,src,traveller);
            }
        }
        traveller.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        vector<int> traveller;
        travel(0,graph,ans,-1,traveller);
        
        return ans;
    }
};