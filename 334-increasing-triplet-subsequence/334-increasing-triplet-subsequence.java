class Solution {
    public boolean increasingTriplet(int[] nums) {
        
        //T : O(n)
        int one,two;
        one=Integer.MAX_VALUE;
        two=Integer.MAX_VALUE;
        
        for(int num : nums)
        {
            if(num <= one)
            {
                one=num;
            }
            else if(num <= two)
            {
                two=num;
            }
            else return true;
        }
        return false;
        
        
        
        
        
        
        /* // T : O(n^2) 
        boolean lCheck,rCheck;
        for(int i=1;i<nums.length-1;i++)
        {
            lCheck=false;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i]) { lCheck=true; break; }
            }
            rCheck=false;
            for(int k=i+1;k<nums.length;k++)
            {
                if(nums[i]<nums[k]) { rCheck=true; break; }
            }
            if(rCheck==true && lCheck==true) return true;
        }
        return false;
        */
    }
}