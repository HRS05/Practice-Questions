class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        long long int sum,i,size;
        size=nums.size();
        sum=0;
        for(i=0;i<size;i=i+2)
        {
            sum=sum+nums[i];
        }
        return sum;
    }
};