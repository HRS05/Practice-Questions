// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int goodValuesCount=0;
        int badValuesCount=0;
        int minBadCount=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k) goodValuesCount++;
        }
        
        if(goodValuesCount==0) return 0;
        int i=0;
        int j=goodValuesCount-1;
        for(int x=0;x<=j;x++)
        {
            if(arr[x]>k) badValuesCount++;
        }
        
        if(badValuesCount < minBadCount) minBadCount=badValuesCount;
        i++;
        j++;
        while(j<n)
        {
            if(arr[i-1]>k) badValuesCount--;
            if(arr[j]>k) badValuesCount++;
            if(badValuesCount < minBadCount) minBadCount=badValuesCount;
            i++;
            j++;
        }
        
        return minBadCount;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends