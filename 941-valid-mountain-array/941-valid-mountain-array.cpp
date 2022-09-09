class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if(arr.size()<3) return false;
        int n=arr.size();
        int i,j;
        for(i=1;i<n;i++)
        {
            if(arr[i-1]>=arr[i]) break;
        }
        for(j=n-2;j>=0;j--)
        {
            if(arr[j+1]>=arr[j]) break;
        }
        if(j==n-2 || i==1) return false;
        return i-1==j+1;
    }
};