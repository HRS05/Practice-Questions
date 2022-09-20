class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& ss) {
        sort(g.begin(),g.end());
        sort(ss.begin(),ss.end());
        int s=0;
        int ans=0;
        for(int i=0;i<g.size() && s<ss.size();i++)
        {
            while(s<ss.size() && g[i] > ss[s]){
                s++;
            }
            if(s<ss.size() && g[i] <= ss[s]) ans++;
            s++;
        }
        return ans;
    }
};