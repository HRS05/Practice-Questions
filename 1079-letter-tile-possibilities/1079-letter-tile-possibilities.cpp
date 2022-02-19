class Solution {
public:
    
    void getCount(string tiles,set<string> &ss,string s,vector<bool> &vis)
    {
        if(s.size()>0) 
        {
           ss.insert(s);
        }
        for(int i=0;i<tiles.size();i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                getCount(tiles,ss,s+tiles[i],vis);
                vis[i]=false;
            }
        }
        return ;
    }

    
    int numTilePossibilities(string tiles) {
        set<string> ss;
        vector<bool> vis(tiles.size(),false);
        getCount(tiles,ss,"",vis);
        return ss.size();
    }
};