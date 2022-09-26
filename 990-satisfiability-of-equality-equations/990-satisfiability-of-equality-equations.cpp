class Solution {
public:
    int find(vector<int> v,int num)
    {
        return v[num]==num ? num : v[num] = find(v,v[num]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> v(26);
        for(int i=0;i<26;i++) v[i]=i;
        for(string e : equations)
        {
            if(e[1]=='=') 
            {
                v[find(v,e[0]-'a')]=v[find(v,e[3]-'a')];
            }
        }
        
        for(string e : equations)
        {
            if(e[1]=='!' && find(v,e[0]-'a') == find(v,e[3]-'a'))
            {
                 return false;
            }
        }
        return true;
    }
};