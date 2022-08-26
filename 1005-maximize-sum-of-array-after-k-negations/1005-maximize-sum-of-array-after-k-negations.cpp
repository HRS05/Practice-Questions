class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(k>0 && nums[i]<0){
                nums[i]*=-1;
                k--;
            }
            sum+=nums[i];
        }
        if(k==0 || k%2==0) return sum;
        sort(nums.begin(),nums.end());
       
        return sum-(2*nums[0]);
    }
};