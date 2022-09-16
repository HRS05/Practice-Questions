class Solution {
public:
    int maxScore(int index,int start,int end,vector<int> &nums,vector<int> &multipliers,vector<vector<int> > &dp)
    {
        if(index==multipliers.size()) return 0;
        if(dp[index][start] != INT_MIN) return dp[index][start];
        int front=(nums[start] * multipliers[index]) + maxScore(index+1,start+1,end,nums,multipliers,dp);
        if(start==end) return dp[index][start] = front;
        int back=(nums[end] * multipliers[index]) + maxScore(index+1,start,end-1,nums,multipliers,dp);
        
            
        return dp[index][start] = max(front,back);
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int start=0;
        int end=nums.size()-1;
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int> > dp(m,vector<int>(m+1,INT_MIN));
        return maxScore(0,start,end,nums,multipliers,dp);
    }
};