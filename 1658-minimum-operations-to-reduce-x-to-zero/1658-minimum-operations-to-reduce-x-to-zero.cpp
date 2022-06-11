class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0, n = nums.size();
        for (int i : nums) sum += i;
        int target = sum - x;
        int curr_sum = 0, max_len = 0;
        int start_idx = 0;
        bool found = false;
        for (int end_idx = 0; end_idx < n; end_idx++) {
            curr_sum += nums[end_idx];
            while (start_idx <= end_idx && curr_sum > target) {
                curr_sum -= nums[start_idx];
                start_idx += 1;
            }
            if (curr_sum == target) {
                found = true;
                max_len = max(max_len, end_idx - start_idx + 1);
            }
        }
        return found ? n - max_len : -1;
}
    /*
    int f(vector<int> &nums,int x,int i,int f)
    {
        if(i<f) return 1e9;
        if(x==0) return 0;
        int c1=1e9;
        int c2=INT_MAX;
        if(x >= nums[i]) c1=1+f(nums,x-nums[i],i-1,f);
        if(x >= nums[f]) c2=1+f(nums,x-nums[f],i,f-1);
        if(c1==1e9 && c2==1e9) return -1;
        return min(c1,c2);
    }
    
    
    int minOperations(vector<int>& nums, int x) {
        return f(nums,x,0,nums.size()-1);
    }
    */
};