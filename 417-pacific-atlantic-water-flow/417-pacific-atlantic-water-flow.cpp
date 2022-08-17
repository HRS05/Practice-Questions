class Solution {
public:
    
    void travel(int i,int j,set<pair<int,int> > &ocean,vector<vector<int> > &heights,int lastHeight)
    {
        int n=heights.size();
        int m=heights[0].size();
        
        if(ocean.find({i,j})!=ocean.end()){
            return;
        }
        if(heights[i][j]>=lastHeight){
            ocean.insert({i,j});
        }else{
            return;
        }
        
        if(i-1 >= 0){
            travel(i-1,j,ocean,heights,heights[i][j]);
        }
        if(i+1 <n){
            travel(i+1,j,ocean,heights,heights[i][j]);
        }
        if(j-1 >= 0){
            travel(i,j-1,ocean,heights,heights[i][j]);
        }
        if(j+1 <m){
            travel(i,j+1,ocean,heights,heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> > ans;
        set<pair<int,int> > atlantic;
        set<pair<int,int> > pacific;
        
        for(int i=0;i<n;i++)
        {
            travel(i,0,pacific,heights,heights[i][0]);
            travel(i,m-1,atlantic,heights,heights[i][m-1]);
        }
        
        for(int i=0;i<m;i++)
        {
            travel(0,i,pacific,heights,heights[0][i]);
            travel(n-1,i,atlantic,heights,heights[n-1][i]);
        }
        
        for(pair<int,int> p : atlantic)
        {
            if(pacific.find(p)!=pacific.end()){
                ans.push_back({p.first,p.second});
            }
        }
        return ans;
    }
};