class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int l=0;
        int h=arr.size();
        int mid;
        while(l<h)
        {
            mid=(l+h)/2;
            if(arr[mid] < arr[mid+1])
              l=mid+1;  
            else 
              h=mid;
        }
        return l;
    }
    
    
    /*
    int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1] > arr[i]) return i-1;
        }
        return -1;
    }*/
};