class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> mp;
        stack<int> s;
        
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(s.empty())
            {
                mp[nums2[i]]=-1;
            }
            else if(!s.empty() && s.top() > nums2[i])
            {
                mp[nums2[i]]=s.top();
            }
            else if(!s.empty() && s.top() <= nums2[i])
            {
                while(!s.empty() && s.top()<=nums2[i]) s.pop();
                if(s.empty()) mp[nums2[i]]=-1;
                else mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(int num : nums1)
        {
            ans.push_back(mp[num]);
        }
        
        return ans;
    }
};