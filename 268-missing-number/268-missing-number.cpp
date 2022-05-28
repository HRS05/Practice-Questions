class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xxor=0;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            xxor^=i ^ nums[i];
        }
        return xxor^nums.size();
    }
};