class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int> > adj(n+1);
        vector<vector<int> > check(n+1);
        for(int i=0;i<trust.size();i++)
        {
            adj[trust[i][1]].push_back(trust[i][0]);
            check[trust[i][0]].push_back(trust[i][1]);
        
        }
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==n-1 && check[i].size()==0) return i;
        }
        return -1;
    }
};