//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool dfs(int i,vector<int> adj[],vector<bool> &v,vector<bool> &pv)
  {
      //if(v[i] && pv[i]) return true;
      //if(v[i]) return false;
      v[i]=pv[i]=true;
      for(int nbr : adj[i])
      {
          if(!v[nbr])
          {
              if(dfs(nbr,adj,v,pv)) return true;
          }
          else if(pv[nbr])
          {
              return true;
          }
      }
      pv[i]=false;
      return false;
  }
  
  
    bool isCyclic(int V, vector<int> adj[]) {
        int n = V;
        vector<bool> v(n,false);
        vector<bool> pv(n,false);
        for(int i=0;i<n;i++)
        {
            if(v[i]==false)
            {
                if(dfs(i,adj,v,pv)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends