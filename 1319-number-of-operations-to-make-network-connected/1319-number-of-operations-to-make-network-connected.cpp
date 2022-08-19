class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> v(n,-1);
        int count=0;
        for(vector<int> i : connections)
        {
            int f=i[0];
            int s=i[1];
            while(v[f]>0)
            {
                f=v[f];
            }
            while(v[s]>0)
            {
                s=v[s];
            }
            if(s==f) continue;
            if(v[f]<v[s])
            {
                v[f]+=v[s];
                v[s]=f;
            }
            else{
                v[s]+=v[f];
                v[f]=s;
            }
        }
        for(int i : v)
        {
            cout<<i<<endl;
            if(i<0) count++;
        }
        return count-1;
    }
};