class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) 
    // {
    //     int n=nums.size();
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i-1;j>=0;j--)
    //         {
    //             if(nums[i] > nums[j]) dp[i]=max(dp[i],dp[j]+1);
    //         }
    //         maxi=max(dp[i],maxi);
    //     }
    //     return maxi;
    // }
    
    
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> tail;
        
        for(int num : nums){
            if(tail.empty() || num > tail.back()){
                tail.push_back(num);
            }
            else{
                tail[firstGreatEqual(tail, num)] = num;
            }
        }
        //for(int i=0;i<tail.size();i++) cout<<tail[i]<<" ";
        return tail.size();
    }
private:
    int firstGreatEqual(vector<int>& t, int tr){
		// For finding the index of target element.
		// Lower_Bound solves via Binary Search.
       
        // the next smallest number just greater than or equal to that number tr in t.
        return lower_bound(t.begin(), t.end(), tr) - t.begin();
    }
    
    
    
    /*
    TC : (n)^2
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] < nums[j])
                {
                    dp[j]=max(dp[j],dp[i]+1);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
            //cout<<"ans -> "<<ans<<endl;
        }
        return ans;
    }
    */
    
    /*
    //recursive solution
    //TC : 2*n
    int f(vector<int> &nums,int index,int lastNumber)
    {
        if(index>=nums.size()) return 0;
        int pick=0;
        int notPick=0;
        if(lastNumber < nums[index]) pick=1+f(nums,index+1,nums[index]);
        notPick=f(nums,index+1,lastNumber);
        return max(pick,notPick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        return f(nums,0,-10001);
    }
    */
};