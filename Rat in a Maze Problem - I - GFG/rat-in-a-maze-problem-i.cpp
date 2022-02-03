// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<string> &ans,vector<vector<int>> &m,vector<vector<bool>> &visited,int i,int j,string path,int n)
    {
        if(i>n-1 || i<0 || j>n-1 || j<0) return;
        if(m[i][j]!=1) return;
        //if(visited[i][j]==true) return;
        /*
        if we dont't want to use extra space for visited
        so, we can just change the value from 1 to 0 for that 
        recursive call see below
        */
        
        if(i==n-1 && j==n-1) 
        {
            ans.push_back(path);
            //cout<<path<<endl;
            return;
        }
        //visited[i][j]=true;
        m[i][j]=0;
        solve(ans,m,visited,i,j+1,path+"R",n);        
        solve(ans,m,visited,i,j-1,path+"L",n);        
        solve(ans,m,visited,i+1,j,path+"D",n);        
        solve(ans,m,visited,i-1,j,path+"U",n);        
        m[i][j]=1;
        //visited[i][j]=1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool> > visited;
        vector<string> ans;
        for(int i=0;i<n;i++) 
        {
            vector<bool> v(n,false);
            visited.push_back(v);
        }
        solve(ans,m,visited,0,0,"",n);        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends