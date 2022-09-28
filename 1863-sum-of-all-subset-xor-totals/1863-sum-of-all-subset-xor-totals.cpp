class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
         int n = nums.size(), bits = 0;
        for (int i=0; i < n; ++i)
            bits |= nums[i];
        int res = bits * pow(2, n-1);
        return res;
    }
};