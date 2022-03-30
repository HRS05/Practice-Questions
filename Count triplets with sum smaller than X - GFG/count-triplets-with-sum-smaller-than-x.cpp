// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	    long long count=0;
	    for(int i=0;i<n-2;i++)
	    {
	        if(arr[i]>=sum) continue;
	        int a,b;
	        a=i+1;
	        b=n-1;
	        while(a<b)
	        {
	            long long num=arr[i]+arr[a]+arr[b];
	            if(num<sum)
	            {
	                count+=b-a;
	                a++;
	            }
	            else
	            {
	                b--;
	            }
	        }
	    }
	    return count;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends