class UnionFind {
    public:
    vector<int> parent,size;
    UnionFind(int n)
    {
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++) parent[i]=i, size[i]=0;
    }

    int find(int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x,int y)
    {
        int i = find(x);
        int j = find(y);
        if(i == j) return false;
        if(size[i] > size[j]){
            size[i] += size[j];
            parent[j] = i;
        }
        else{
            size[j] += size[i];
            parent[i] = j;
        }
        return true;   
    }
};


class Solution {
public:
    //union find solution
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        int ans = 0;
        UnionFind u(n);
        unordered_map<int,unordered_multiset<int>> mp;
        for(auto p : allowedSwaps){
            u.uni(p[0],p[1]);
        }

        for(int i=0;i<n;i++){
            if(source[i] == target[i]) continue;
            mp[u.find(i)].insert(source[i]);
        }
        for(int i=0;i<n;i++){
            if(source[i] == target[i]) continue;
            auto &st = mp[u.find(i)];
            auto it = st.find(target[i]);
            if (it != end(st)) {
                st.erase(it);
            } else
                ++ans;
        }
        return ans;
    }



    /* dfs solution approach
        1. here we trverse in all component of graph 
        2. check the common number of data in that traversal indexes in both sorce and target 
        3. in ans we increase count to uncomman number of indexes
    */
    // int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
    //         int n = source.size();
    //         vector<vector<int> > adj(n);
    //         vector<bool> vis(n,false);
    //         vector<int> data;
    //         int ans = 0;
    //         for(auto p : allowedSwaps){
    //             adj[p[0]].push_back(p[1]);
    //             adj[p[1]].push_back(p[0]);
    //         }

    //         function<void (int) > dfs; 
    //         dfs = [&] (int index) -> void {
    //             if(vis[index]) return;
    //             vis[index] = true;
    //             data.push_back(index);
    //             for(int nbr : adj[index]){
    //                 dfs(nbr);
    //             }
    //         };

    //         for(int i=0;i<n;i++)
    //         {
    //             if(vis[i]) continue;
    //             unordered_map<int,int> mp;
    //             dfs(i);
    //             for(int x : data) mp[source[x]]++;
    //             for(int x : data) {
    //                 if(mp[target[x]] < 1) ans++;
    //                 mp[target[x]]--;
    //             }
    //             data.clear();
    //         } 

    //         return ans;

    //     }
    
};