class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     
    //wonderful solution    
    int count = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i-1]) count++;
        else nums[i-count] = nums[i];
    }  
    return nums.size()-count;
        /*
        //my solution
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
        */
    }
};