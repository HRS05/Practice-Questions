class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int> > adj(n);
        vector<int> time(n,-1);
        queue<int> q;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        q.push(0);
        time[0]=0;
        while(!q.empty())
        {
            int node=q.front(); q.pop();
            for(int nbr : adj[node])
            {
                if(time[nbr] == -1)
                {
                    time[nbr]=time[node]+1;
                    q.push(nbr);
                }
            }
        }
        
        int res=0;
        for(int i=1;i<n;i++)
        {
            // int timeTaken=time[i]*2 -1;
            // if(timeTaken < patience[i]) {
            //     res=max(res,timeTaken+1);
            // }
            // else {
            //     //int out=timeTake/patience[i];
            //     res=max(res,(timeTaken+timeTaken+1));
            // }            
            int extraPayload = (time[i]*2 - 1)/patience[i]; 
            
            int lastOut = extraPayload * patience[i]; 
            int lastIn = lastOut + time[i]*2; 
			res=max(res,lastIn);

                
        }
        
        return res+1;
    }
};