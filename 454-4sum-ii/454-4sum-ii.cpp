class Solution {
public:
    
    
    //TC : O(n^2)
    //SC : O(n^2)
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp;
        int n=nums1.size();
        int count=0;
        for(int num1 : nums1)
        {
            for(int num2 : nums2)
            {
                mp[num1+num2]++;
            }
        }
        for(int num3 : nums3)
        {
            for(int num4 : nums4)
            {
                //commented because if map contains one element 
                //so in that case whatever we are finding if that 
                // is in map for which must be the mp.end()
                
                //if(mp.find(mp[-(num3+num4)])!=mp.end()) 
                    count+=mp[-(num3+num4)];
                
            }
        }
        return count;
    }
};