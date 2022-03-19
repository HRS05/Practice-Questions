// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    void segregateElements(int arr[],int n)
    {
        int v[n];
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > 0)
            v[j++]=arr[i];
        }
        
        if(j==n || j==0) return;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] < 0)
            v[j++]=arr[i];
        }
        
        memcpy(arr,v,sizeof(v));
    }
    
    /*
    // solution with no space
    void swapp(int i,int j,int arr[])
    {
        int x=i;
        int y=j;
        int num=arr[j];
        while(y>i)
        {
            arr[y]=arr[y-1];
            y--;
        }
        arr[i]=num;
    }
    
    void segregateElements(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                int j=i+1;
                while(j<n && arr[j]<0) j++;
                if(j<n && arr[j]>0)swapp(i,j,arr);
            }
        }
    }
    */
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
  // } Driver Code Ends