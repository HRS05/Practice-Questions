class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        long num=nums[0];
        int val;
        for(int i=1;i<nums.size();i++) num^=nums[i];
        int rmsb= num & (-num);
        int a,b;
        a=b=0;
        for(int n : nums)
        {
            if(n & rmsb) a^=n;
            else b^=n;
        }
        ans.push_back(a);
        ans.push_back(b);
        
        return ans;
    }
};