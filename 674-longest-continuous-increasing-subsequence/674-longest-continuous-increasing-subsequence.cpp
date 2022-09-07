class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1;
        int countTillNow=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i==0 || nums[i-1] < nums[i])
            {
                countTillNow++;
            }
            else
            {
                count=max(count,countTillNow);
                countTillNow=1;
            }
        }
        count=max(count,countTillNow);
        return count;
    }
};