class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int size=nums.length;
        int rep=size/3;
        List<Integer> l=new ArrayList<Integer>();
        Map<Integer,Integer> mp=new HashMap<Integer,Integer>();
        for(Integer num : nums)
        {
            if(mp.get(num)!=null) mp.put(num,mp.get(num)+1);
            else mp.put(num,1);
        }
        for(Map.Entry<Integer,Integer> entry : mp.entrySet())
        {
            if(entry.getValue() > rep) l.add(entry.getKey());
        }
            
        return l;
    }
}