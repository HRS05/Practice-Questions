class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size()<=2) return ans;
        sort(nums.begin(),nums.end());
        //a+b+c=0;
        for(int a=0;a<nums.size()-2;a++)
        {
            if(a>0 && nums[a]==nums[a-1]) continue;
            int b=a+1;
            int c=nums.size()-1;
            while(b<c)
            {
                int sum=nums[a]+nums[b]+nums[c];
                if(sum<0)
                {
                    b++;
                }
                else if(sum>0)
                {
                    c--;
                }
                else
                {
                    ans.push_back(vector<int>{nums[a],nums[b],nums[c]});
                    b++; c--;
                    while(b < c && nums[b]==nums[b-1]) b++;
                    while(b < c && nums[c]==nums[c+1]) c--;
                }
            }
        }
            
        return ans;
    }
};