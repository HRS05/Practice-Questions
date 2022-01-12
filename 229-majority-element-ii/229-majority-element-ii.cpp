class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size=nums.size();
        int rep=size/3;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<size;i++)
        {
            int count=1;
            int j=i+1;
            while(j<size && nums[j]==nums[i])
            {
                
                count++;
                j++;
            }
            if(count > rep) ans.push_back(nums[i]);
            i=--j; //i=j-1;
        }
        
        /*
        map<int,int> mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        for(auto x : mp)
        {
            if(x.second > rep) ans.push_back(x.first);
        }
        */
        
        return ans;
    }
};