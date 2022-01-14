class Solution {
    public int[] sortArrayByParity(int[] nums) {
        
        //method 1
        int j=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] % 2 == 0)
            {
                int g=nums[i];
                nums[i]=nums[j];
                nums[j]=g;
                j++;
            }
        }
        return nums;
        
        /* //method 2
        // two pointer
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
        */
    }
}