// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        
        
        long long water=0;
        long long max=0;
        vector<int> preSum(n);
        vector<int> sufSum(n);
        for(int i=0;i<n;i++)
        {
            if(max<arr[i]) max=arr[i];
            preSum[i]=max;
        }
        max=0;
        for(int i=n-1;i>=0;i--)
        {
            if(max<arr[i]) max=arr[i];
            sufSum[i]=max;
        }
        
        for(int i=1;i<n-1;i++)
        {
            water+=min(preSum[i],sufSum[i])-arr[i];
        }
        
        return water;
        
        
        /*
           // this is brut force app.
           
        long long water=0;
        for(int i=1;i<n-1;i++)
        {
            int lm,rm;
            int lmi,rmi;
            
            lm=rm=arr[i];
            lmi=i-1;
            rmi=i+1;
            while(lmi>=0)
            {
                if(arr[lmi]>lm) lm =arr[lmi];
                lmi--;
            }
            while(rmi<n)
            {
                if(arr[rmi]>rm) rm=arr[rmi];
                rmi++;
            }
            if(rm!=arr[i] && lm!=arr[i])
            {
                water+=min(lm,rm)-arr[i];
            }
        }
        return water; */
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends