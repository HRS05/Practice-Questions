class Solution {
public:
    
    int getLowerBound(vector<int> &nums,int target,int low,int high)
    {
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    
    
    int getUpperBound(vector<int> &nums,int target,int low,int high)
    {
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(nums[mid]==target) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int size=nums.size()-1;
        int low=0;
        int high=size;
        int mid;
        vector<int> ans(2,-1);
        while(low <= high){
            mid=(low+high)/2;
            if(nums[mid]==target)
            {
                if(nums[low]!=target)
                {
                    low=getLowerBound(nums,target,low,mid);
                }
                if(nums[high]!=target)
                {
                    high=getUpperBound(nums,target,mid,high);
                }
                ans[0]=low;
                ans[1]=high;
                break;
            }
            else if(nums[mid] > target && nums[high]!=target)
            {
                high=mid-1;
            }
            else if(nums[mid] < target && nums[low]!=target)
            {
                low=mid+1;
            }
        }
            
            
        return ans;
    }
};