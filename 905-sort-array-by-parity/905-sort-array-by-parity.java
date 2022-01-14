class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int j=0;
        int i=nums.length-1;
        while(j<i)
        {
            if(nums[i]%2==0 && nums[j]%2!=0) 
            {
                int g=nums[i];
                nums[i]=nums[j];
                nums[j]=g;
                i--; j++;
            }
            if(nums[j]%2==0)
            {
                j++;
            }
            if(nums[i]%2!=0)
            {
                i--;
            }
                
        }
        return nums;
    }
}