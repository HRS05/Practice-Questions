// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int arr[], int size)
{
        int candidate;
        int vote=0;
        for(int i=0;i<size;i++)
        {
            if(vote==0)
            {
                candidate=arr[i];
                vote++;
            }
            else
            {
                if(arr[i]==candidate)
                {
                    vote++;
                }
                else
                {
                    vote--;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==candidate) count++;
        }
        if(count > size/2) 
        return candidate;
        return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends