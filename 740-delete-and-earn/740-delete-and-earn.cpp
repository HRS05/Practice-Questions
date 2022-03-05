class Solution {
public:
    int f(vector<int> &nums,int index,vector<int> &dp)
    {
        if(index<0) return 0;
        int sum=0;
        int i=index;
        if(dp[index]!=-1) return dp[index];
        while(i>=0 && nums[i]==nums[index])
        {
            sum+=nums[i];
            i--;
        }
        int x=i;
        while(i>=0 && nums[i]==nums[index]-1)
        {
            i--;
        }
        return dp[index]=max((sum+f(nums,i,dp)),f(nums,x,dp));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),-1);
        return f(nums,nums.size()-1,dp);
    }
    
    
    
    /*
    int f(vector<int> &nums,map<int,bool> &mp,int index)
    {
        if(index<0)
        {
            return 0;
        }
        int take=0;
        if(mp[nums[index]])
        {
        if(mp.find(nums[index]+1)!=mp.end()) mp[nums[index]+1]=false;
        if(mp.find(nums[index]-1)!=mp.end()) mp[nums[index]-1]=false;
        take=nums[index]+f(nums,mp,index-1);
        if(mp.find(nums[index]+1)!=mp.end()) mp[nums[index]+1]=true;
        if(mp.find(nums[index]-1)!=mp.end()) mp[nums[index]-1]=true;
        }
        int notTake=0;
        notTake=f(nums,mp,index-1);
        cout<<"Index : "<<index<<endl;
        cout<<"take : "<<take<<"  notTake : "<<notTake<<endl;
        return max(take,notTake);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        map<int,bool> mp;
        for(int num : nums)
        {
            mp[num]=true;
        }
      return f(nums,mp,nums.size()-1);
    }
    */
};