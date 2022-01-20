class Solution {
    
    void check(int[] nums,List<List<Integer>> ans,List<Integer> l,int index)
    {
        if(index>=nums.length) 
        {
            ans.add(new ArrayList<Integer>(l));
            //System.out.println(l);
            return;
        }
        l.add(nums[index]);
        //System.out.println(l);
        check(nums,ans,l,index+1);
        l.remove(l.size()-1);
        check(nums,ans,l,index+1);
    }
    
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans=new ArrayList<List<Integer> >();
        List<Integer> l=new ArrayList<Integer>();
        check(nums,ans,l,0);
        return ans;
        
    }
}