class Solution {
public:
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
            if(mp[num]>0) mp[num]--;
            if(mp.find(x)!=mp.end() && mp[x]>0){
                mp[x]--;
                count++;
            }
            else{
                mp[num]=0;
            }
        }
        return count;
    }
};