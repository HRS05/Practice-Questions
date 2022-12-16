class Solution {
public:
    bool solve(vector<int> &arr,int node,vector<int> &v)
    {
        int n = arr.size();
        if(v[node]!=-1) return v[node];
        v[node] = 0;
        if(arr[node] == 0) return true;
        if(node-arr[node] >=0 )v[node] |= solve(arr,node-arr[node],v);
        if(node+arr[node] <n )v[node] |= solve(arr,node+arr[node],v);
        
        return v[node];
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> v(n,-1);
        return solve(arr,start,v);
    }
};