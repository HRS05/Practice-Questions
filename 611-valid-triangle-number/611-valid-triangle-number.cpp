class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int k=i+2;
            int j=i+1;
            while(j < n-1 && nums[i] != 0)
            {
                while(k < n && nums[i] + nums[j] > nums[k])
                    k++;
                ans += k-j-1;
                j++;
            }
        }
        
        
        return ans;
    }
};