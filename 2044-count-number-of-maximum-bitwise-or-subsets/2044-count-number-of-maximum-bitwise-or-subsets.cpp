class Solution {
public:
    
    int f(vector<int> &nums,int result,int cal,int index)
    {
        int res=0;
        if(index<0) return 0;
        if(result == (cal | nums[index]))
        {
            res++;
        }
        int take=f(nums,result,cal|nums[index],index-1);
        int notTake=f(nums,result,cal,index-1);
        return res+take+notTake;
    }
    
    
    int countMaxOrSubsets(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result=result | nums[i];
        }
        
        return f(nums,result,0,nums.size()-1);
    }
};