// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    bool first=true;
    int l;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x && first)
        {
            ans.push_back(i);
            first=false;
        }
        if(arr[i]==x)
        {
            l=i;
        }
        
    }
    if(ans.size()==0) return vector<int>{-1,-1};
    ans.push_back(l);
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends