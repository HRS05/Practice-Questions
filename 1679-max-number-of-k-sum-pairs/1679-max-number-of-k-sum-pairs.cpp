class Solution {
public:
    
    
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum==k) {
                count++;
                i++;
                j--;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
    
    
    /*
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        map<int,int> mp;
        for(int num : nums)
        {
            int target=k-num;
            if(mp[target]>0)
            {
                count++;
                mp[target]--;
            }
            else mp[num]++;
        }
        return count;
    }
    */
    
    /*
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        map<int,int> mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        for(int num : nums)
        {
            int x=k-num;
            if(mp[num]==0) continue;
            
            if(mp[x]>0){
                mp[x]--;
                mp[num]--;
                count++;
            }
            else{
                mp[num]=0;
            }
        }
        return count;
    }
    */
};