class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> color(n,0);    
        for(int i=0;i<n;i++)                 // traverse each component
        {
            if(color[i]) continue;          // if already coloured then continue
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty())
            {
                int parent=q.front();
                q.pop();
                for(int child:graph[parent])
                {
                    if(color[child]==0)
                    {
                        color[child]=-color[parent];
                        q.push(child);
                    }
                    else
                    {
                        if(color[parent]==color[child]) return false;    
                        // if parent and child have same colour then return false;
                    }
                }
            }

        }
        return true;
    }
    /*
    //TLE solution
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> set(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(set[i]==-1){
            if(! check(graph,set,i)) return false;
            }
        }
        return true;
    }
    
    bool check(vector<vector<int >>& graph,vector<int> set,int nodeIndex)
    {
        if(set[nodeIndex]==-1) set[nodeIndex]=1;
        for(int x:graph[nodeIndex])
        {
            if(set[x]==-1)
            {
                set[x]=1-set[nodeIndex];
                if(! check(graph,set,x)) return false;
            }
            else if(set[x]==set[nodeIndex])
            {
                return false;
            }
        }
        return true;
    }
    */
};