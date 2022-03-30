class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans;
        int x=INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {
            int a=i+1;
            int b=nums.size()-1;
            while(a<b)
            {
                int num=nums[i]+nums[a]+nums[b];
                if(abs(num-target)<x) 
                {
                    x=abs(num-target);
                    ans=num;
                }
                if(num>target) b--;
                else if(num<target) a++;
                else return target;
            }
        }
        return ans;
    }
};