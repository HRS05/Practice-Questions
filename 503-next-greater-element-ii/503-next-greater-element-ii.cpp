class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int i=(2*n)-1;i>=0;i--)
        {
            if(s.empty())
            {
                ans[i % n]=-1;
            }
            else if(!s.empty() && s.top() > nums[i % n])
            {
                ans[i % n]=s.top();
            }
            else if(!s.empty() && s.top() <= nums[i % n])
            {
                while(!s.empty() && s.top() <= nums[i % n]) s.pop();
                if(s.empty()) ans[i % n]=-1;
                else ans[i % n]=s.top();
            }
            s.push(nums[i % n]);
        }
        return ans;
    }
};