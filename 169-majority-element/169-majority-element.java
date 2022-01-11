class Solution {
    public int majorityElement(int[] nums) {
        int me,count;
        me=0;
        count=0;
        for(int i=0;i<nums.length;i++)
        {
            if(count==0)
            {
                me=nums[i];
            }
            count += (me==nums[i]) ? 1 : -1;
        }
        return me;
    }
}