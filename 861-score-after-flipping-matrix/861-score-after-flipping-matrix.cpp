class Solution {
public:
    
    int getValue(vector<int> v)
    {
        string tmp="";
        for(int i=0;i<v.size();i++)
        {
            tmp+=to_string(v[i]);
        }
        return stoi(tmp,0,2);
    }
    
    void flip(string s,int index,vector<vector<int> > &grid){
        int n=grid.size();
        int m=grid[0].size();
        if(s=="row"){
            for(int i=0;i<m;i++)
            {
                if(grid[index][i]==1) grid[index][i]=0;
                else grid[index][i]=1;
            }
        }
        if(s=="column"){
            for(int i=0;i<n;i++)
            {
                if(grid[i][index]==1) grid[i][index]=0;
                else grid[i][index]=1;
            }
        }
    }
    
    
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0) flip("row",i,grid);
        }
        for(int i=1;i<m;i++)
        {
            int oneCount=0;
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==1) oneCount++;
            }
            if(oneCount<= n/2) flip("column",i,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=getValue(grid[i]);
        }
        return ans;
    }
};