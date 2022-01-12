class Solution {
    public int subarraySum(int[] nums, int k) {
        // T - O(n)
        // S - O(n)
        int count=0;
        int sum=0;
        Map<Integer,Integer> mp=new HashMap<Integer,Integer>();
        mp.put(0,1);
        for(int num : nums)
        {
            sum+=num;
            if(mp.containsKey(sum-k))
            {
                count+= mp.get(sum-k);
            }
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return count;
        
        
        /* //T= O(n^2)
        int sum=0;
        int count=0;
        for(int i=0;i<nums.length;i++)
        {
            int j=i;
            sum=0;
           while(j<nums.length)
           {
              
               sum+=nums[j];
                if(sum==k) count++;
               j++;
           }
        }
        return count;
        */
    }
}