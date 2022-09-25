class Solution {
public:
    
    bool nextPermutation(string& nums) 
    {
        int i=nums.size()-1;
        while(i>=1)
        {
            if(nums[i-1] < nums[i]) break;
            i--;
        }
        if(i==0) 
        {
            return false;
        }
        int j=nums.size()-1;
        while(j>=0)
        {
            if(nums[j]>nums[i-1]) break;
            j--;
        }
        char g=nums[j];
        nums[j]=nums[i-1];
        nums[i-1]=g;
        
        int l,r;
        r=nums.size()-1;
        l=i;
        while(l<r)
        {
            char g=nums[l];
            nums[l]=nums[r];
            nums[r]=g;
            l++;  r--;
        }   
        return true;
    }
    
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(!nextPermutation(s)) return -1;
        long x=stoll(s);
        if(x <= INT_MAX) return x;
        return -1;
    }
};