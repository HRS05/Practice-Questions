
class Solution {
public:
    
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if(nums.size()<4) return ans; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            long long num=target-nums[i];
            for(int a=i+1;a<nums.size()-2;a++)
            {
            if(a>i+1 && nums[a]==nums[a-1]) continue;
            long long b=a+1;
            long long c=nums.size()-1;
            while(b<c)
            {
                long long sum=nums[a]+nums[b];
                sum+=nums[c];
                if(sum<num)
                {
                    b++;
                    while(b < c && nums[b]==nums[b-1]) b++;
                }
                else if(sum>num)
                {
                    c--;
                    while(b < c && nums[c]==nums[c+1]) c--;
                }
                else
                {
                    ans.push_back(vector<int>{nums[i],nums[a],nums[b],nums[c]});
                    b++; c--;
                    while(b < c && nums[b]==nums[b-1]) b++;
                    while(b < c && nums[c]==nums[c+1]) c--;
                }
            }
            }
            
        }
        return ans;
    }
};