class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>=1)
        {
            if(nums[i-1] < nums[i]) break;
            i--;
        }
        if(i==0) 
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int j=nums.size()-1;
        while(j>=0)
        {
            if(nums[j]>nums[i-1]) break;
            j--;
        }
        int g=nums[j];
        nums[j]=nums[i-1];
        nums[i-1]=g;
        
        int l,r;
        r=nums.size()-1;
        l=i;
        while(l<r)
        {
            int g=nums[l];
            nums[l]=nums[r];
            nums[r]=g;
            l++;  r--;
        }
        
    }
};