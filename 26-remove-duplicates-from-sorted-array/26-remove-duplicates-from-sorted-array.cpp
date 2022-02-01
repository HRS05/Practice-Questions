class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        i=1;
        j=1;
        if(nums.size()==0) return 0;
        for(j=1;j<nums.size();j++)
        {
            if(nums[i-1]<nums[j])
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};