class Solution {
public:
    
    int rob1(vector<int>& nums,int low,int high) {
        
        int ans=nums[low];
        int i2;
        int i1;
        i1=ans;
        i2=ans;
        for(int i=low+1;i<high;i++)
        {
            int take;
            if(i-2 >= low)take=nums[i]+i2;
            else take=nums[i];
            int notTake=i1;
            ans=max(take,notTake);
            i2=i1;
            i1=ans;
            
        }
        return ans;
    }
    
    
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
       return max(rob1(nums,0,nums.size()-1),rob1(nums,1,nums.size()));
    }
};