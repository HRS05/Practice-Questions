class Solution {
public:
    
    int find(int i,int f,vector<int> &nums,int target)
    {
        if(i>f) return -1;
        while(i<=f)
        {
            int mid=(i+f)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) f=mid-1;
            else i=mid+1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int i;
        for(i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) break;
        }
        
        int x=find(0,i,nums,target);
        if(x!=-1) return x;
        int y=find(i+1,nums.size()-1,nums,target);
        if(y!=-1) return y;
        return -1;
    }
};