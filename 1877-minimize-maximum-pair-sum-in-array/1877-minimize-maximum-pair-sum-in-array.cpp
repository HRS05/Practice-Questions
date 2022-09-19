class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int i=0;
        int f=nums.size()-1;
        int ans=0;
        while(i<f)
        {
            ans=max(ans,(nums[i]+nums[f]));
            i++;
            f--;
        }
        return ans;
    }
};